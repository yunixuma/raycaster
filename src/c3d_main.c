/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/24 23:09:14 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_main_scene(t_scene *scene, char *fpath)
{
	int		fd;

	c3d_scene_init(scene);
	fd = c3d_scene_open(fpath);
	if (fd < 0)
		return (errno);
DI(fd);
	if (c3d_scene_def(scene, fd))
		return (c3d_scene_clean(scene, errno));
	scene->map = c3d_scene_getmap(fd);
	if (errno)
		return (c3d_scene_clean(scene, errno));
	close(fd);
	return (ERR_NOERR);
}

static int	c3d_main_opt(t_opt *opt, t_scene *scene)
{
	size_t	i;

	i = 0;
	while (i < N_DIRECTION)
		opt->vecs[i++] = NULL;
	opt->size = ft_mapsize(scene->map);
	if (c3d_map2vectors(opt, scene))
		return (c3d_scene_clean(scene, errno));
debug_c3d_f_vecs(opt);
	return (ERR_NOERR);
}

static int	c3d_main_mlx(t_scene *scene, t_opt *opt)
{
	t_mlx	mlx;

	mlx.scene = scene;
	mlx.opt = opt;
	if (c3d_mlx_init(&mlx))
		return (errno);
DP(mlx.scene->map);
	ft_putendl_fd(MSG_WAIT, STDOUT_FILENO);
	if (c3d_win_init(&mlx))
		return (c3d_exit_mlx(&mlx, errno));
DP(&mlx.win);
	if (c3d_img_init(&mlx))
		return (c3d_exit_mlx(&mlx, errno));
DP(&mlx.img[IDX_HUD]);
	c3d_render_hud_init(&mlx);
	c3d_win_draw_vision(&mlx);
	c3d_print_control();
	return (c3d_mlx_loop(&mlx));
}

int	main(int argc, char *argv[])
{
	t_scene	scene;
	t_opt	opt;

	errno = 0;
	if (argc < OFFSET_ARG + IDX_ARG)
		return (c3d_print_err(ERR_NOARG));
	if (argc > OFFSET_ARG + IDX_ARG)
		return (c3d_print_err(ERR_MANYARGS));
	if (c3d_main_scene(&scene, argv[IDX_ARG]))
		return (c3d_print_err(errno));
	if (c3d_main_opt(&opt, &scene))
		return (c3d_print_err(errno));
debug_c3d_scene(&scene);
	c3d_main_mlx(&scene, &opt);
	return (ERR_NOERR);
}
