/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/24 14:27:18 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_mlx_init_scale(t_addr *size)
{
	int	scale;

	scale = SIZE_CELL;
	while (scale > 0)
	{
		if (scale * size->x * RATIO_HUD < WIDTH_VISION \
			&& scale * size->y * RATIO_HUD < HEIGHT_VISION)
			return (scale);
		scale--;
	}
	return (1);
}

int	c3d_mlx_init(t_mlx *mlx)
{
	size_t	i;

	mlx->conn = mlx_init();
	if (!mlx->conn)
		return (ft_seterr(ERR_MLX));
	c3d_game_init(&mlx->game, mlx->scene);
	mlx->win = NULL;
	i = 0;
	while (i < N_TEXTURE + 1)
		mlx->img[i++].ptr = NULL;
	mlx->scale = c3d_mlx_init_scale(&mlx->opt->size);
	return (ERR_NOERR);
}

int	c3d_mlx_hook(t_mlx *mlx)
{
debug_printf("event: %#04x\n", mlx->game.event);
debug_printf("key: %#06x\n", mlx->game.key);
	if (mlx->game.event == FLAG_NOEVENT)
		return (false);
	c3d_game_keyhook_fire(mlx->game.key, mlx);
	c3d_win_draw_vision(mlx);
	mlx->game.event &= (FLAG_KEYDOWN | FLAG_CURSOR);
	return (true);
}

int	c3d_mlx_loop(t_mlx *mlx)
{
	mlx_hook(mlx->win, EVENT_KEYDOWN, MASK_STRUCT << SHIFT_KEYDOWN, &c3d_game_keyhook_down, mlx);
	mlx_hook(mlx->win, EVENT_KEYUP, MASK_STRUCT << SHIFT_KEYUP, &c3d_game_keyhook_up, mlx);
	mlx_mouse_hook(mlx->win, &c3d_game_clickhook, mlx);
//	mlx_hook(mlx->win, EVENT_MOUSERELEASE, MASK_STRUCT << EVENT_MOUSERELEASE, &c3d_game_clickhook_up, mlx);
	mlx_hook(mlx->win, EVENT_MOUSEMOVE, MASK_STRUCT << EVENT_MOUSEMOVE, \
		&c3d_game_cursorhook, mlx);
	mlx_hook(mlx->win, EVENT_DESTROY, MASK_STRUCT, &c3d_exit_mlx_break, mlx);
	mlx_expose_hook(mlx->win, &c3d_win_draw_vision, mlx);
	mlx_loop_hook(mlx->conn, &c3d_mlx_hook, mlx);
	mlx_loop(mlx->conn);
	return (c3d_exit_mlx(mlx, ERR_NOERR));
}
