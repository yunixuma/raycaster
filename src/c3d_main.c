/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/10 01:46:54 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_main_scene(t_scene *scene, char *fpath)
{
	int		fd;
	t_list	*lst;
	int		errnum;

	c3d_scene_init(scene);
	fd = c3d_scene_open(fpath);
DI(fd);
	errnum = c3d_scene_def(scene, fd);
	if (errnum)
		return (c3d_clean(scene, errnum));
	lst = c3d_map_read(fd);
	c3d_map_trim(&lst);
	c3d_map_chk(&lst);
	scene->map = c3d_lst2map_rect(&lst);
debug_c3d_map_raw(scene->map);
	c3d_map_encode(scene->map);
debug_c3d_map_flag(scene->map);
	c3d_map_valid(scene->map);
	scene->size = ft_mapsize(scene->map);
	close(fd);
	return (ERR_NOERR);
}

static int	c3d_main_win(t_scene *scene)
{
	t_mlx	mlx;

	mlx.scene = scene;
	c3d_mlx_init(&mlx);
	DP(mlx.scene->map);
	ft_putendl_fd(MSG_WAIT, STDOUT_FILENO);
	c3d_win_init(&mlx);
	c3d_img_init(&mlx);
	c3d_win_draw_vision(&mlx);
	ft_putendl_fd(MSG_HOWTO_MOVE, STDOUT_FILENO);
	mlx_hook(mlx.win, EVENT_KEYDOWN, MASK_STRUCT, &c3d_game_keyhook, &mlx);
	mlx_hook(mlx.win, EVENT_MOUSEMOVE, MASK_STRUCT << EVENT_MOUSEMOVE, \
		&c3d_game_cursorhook, &mlx);
	mlx_hook(mlx.win, EVENT_DESTROY, MASK_STRUCT, &c3d_exit_mlx_break, &mlx);
	mlx_expose_hook(mlx.win, &c3d_win_draw_vision, &mlx);
	mlx_loop_hook(mlx.conn, &c3d_mlx_hook, &mlx);
	mlx_loop(mlx.conn);
	return (ERR_NOERR);
}

int	main(int argc, char *argv[])
{
	t_scene	scene;
	int		errnum;

	if (argc < OFFSET_ARG + IDX_ARG)
		c3d_exit(ERR_NOARG);
	if (argc > OFFSET_ARG + IDX_ARG)
		c3d_exit(ERR_MANYARGS);
	errnum = c3d_main_scene(&scene, argv[IDX_ARG]);
	if (errnum)
		return (errnum);
	debug_c3d_scene(&scene);
	c3d_main_win(&scene);
	c3d_clean(&scene, ERR_NOERR);
	return (ERR_NOERR);
}
