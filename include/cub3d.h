/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/08 23:25:34 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "cub3d_math.h"
# include "mlx.h"
# include "libft.h"
# include "cub3d_string.h"
# include "cub3d_const.h"
# include "cub3d_flag.h"
/*# ifdef __MACH__
#  include "cub3d_event_mac.h"
# else*/
# include "cub3d_event.h"
//# endif
# include "cub3d_typedef.h"
# ifdef DEBUG_MODE
#  include "debug_cub3d.h"
# endif

int			main(int argc, char *argv[]);
void		c3d_scene_init(t_scene *scene);
int			c3d_scene_open(char *fpath);
int			c3d_scene_def(t_scene *scene, int fd);
int			c3d_scene_def_color(int *color_code, char *line);
t_list		*c3d_map_read(int fd);
int			c3d_map_trim(t_list **lst);
int			c3d_map_chk(t_list **lst);
char		**c3d_lst2map_rect(t_list **lst);
int			c3d_map_encode(char **map);
int			c3d_map_valid(char **map);
t_addr		ft_mapseek(char **map, char ch);
int			ft_mapseek_exist(char **map, char ch);
t_addr		ft_mapsize(char **map);
void		c3d_map_clear_check(char **map);
void		*c3d_map_clear_free(char **map);
int			c3d_clean(t_scene *scene, int errnum);
void		c3d_mlx_init(t_mlx *mlx);
int			c3d_mlx_hook(t_mlx *mlx);
void		c3d_win_init(t_mlx *mlx);
int			c3d_win_draw_vision(t_mlx *mlx);
void		c3d_win_draw_pixel(t_mlx *mlx, int x, int y, int color);
void		c3d_win_destroy(t_mlx *mlx);
void		c3d_img_init(t_mlx *mlx);
void		c3d_img_destroy(t_mlx *mlx);
void		c3d_render_background(t_mlx *mlx);
void		c3d_render_visible(t_mlx *mlx);
void		c3d_render_rectangle(t_img *img, \
	int color_code, t_addr *zero, t_addr *area);
void		c3d_render_imgpixel(t_img *img, \
	int src_id, t_addr *dst, t_addr *src);
void		c3d_render_imgline(t_img *img, \
	int src_id, t_addr *dst, t_addr *src);
void		c3d_game_init(t_game *game, t_scene *scene);
int			c3d_game_keyhook(int key, t_mlx *mlx);
int			c3d_game_move(t_mlx *mlx, t_coord *move);
int			c3d_game_turn(t_mlx *mlx, t_angle *turn);
int			c3d_game_lens(t_mlx *mlx, double fov_add);
int			c3d_game_judge(t_mlx *mlx);
int			c3d_exit(int errnum);
int			c3d_exit_lst(int errnum, t_list **lst);
int			c3d_exit_map(int errnum, char **map);
int			c3d_exit_mlx(int errnum, t_mlx *mlx);
int			c3d_exit_mlx_goal(int errnum, t_mlx *mlx);
int			c3d_exit_mlx_break(t_mlx *mlx);
int			c3d_print_err(int errnum);
void		c3d_print_score(int score);
void		c3d_print_goal(int score);
void		c3d_print_break(void);
int			c3d_color_combine(t_color *color);
void		c3d_color_separate(t_color *color, int color_code);
void		*ft_free(void **p);
int			ft_hasflag(int val, int flag);
bool		ft_stris(const char *str, int (*f)(int));
long long	ft_math_dtoll(double num);
double		ft_math_deg2rad(double deg);
double		ft_math_rad2deg(double rad);
double		ft_math_angle_normalize(double angle);
double		ft_math_distance_2d(t_coord *pt1, t_coord *pt2);
double		ft_math_distance_3d(t_coord *pt1, t_coord *pt2);
int			ft_math_intersect_2d(t_vec *vec1, t_vec *vec2, t_coord *pt);
void		ft_coord_init(t_coord *pt);
void		ft_coord_copy(t_coord *dst, t_coord *src);

#endif
