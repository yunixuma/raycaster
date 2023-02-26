/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/26 14:50:43 by Yoshihiro K      ###   ########.fr       */
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
# include "ft_prompt.h"
# include "cub3d_string.h"
# include "cub3d_const.h"
# include "cub3d_flag.h"
# include "cub3d_render_vision.h"
# ifndef RC_MODE
#  define RC_MODE	0
# endif
/*# ifdef __MACH__
#  include "cub3d_event_mac.h"
# else*/
# include "cub3d_event.h"
//# endif
# include "cub3d_typedef.h"
# ifdef DEBUG_MODE
#  include "debug_cub3d.h"
# endif

int		main(int argc, char *argv[]);
void	c3d_scene_init(t_scene *scene);
int		c3d_scene_open(char *fpath);
int		c3d_scene_def(t_scene *scene, int fd);
int		c3d_scene_def_color(int *color_code, char *line);
char	**c3d_scene_getmap(int fd);
int		c3d_scene_clean(t_scene *scene, int errnum);
t_list	*c3d_map_read(int fd);
int		c3d_map_trim(t_list **lst);
int		c3d_map_chk(t_list **lst);
char	**c3d_lst2map_rect(t_list **lst);
int		c3d_map_encode(char **map);
int		c3d_map_valid(char **map);
t_addr	ft_mapseek(char **map, char ch);
bool	ft_mapseek_exist(char **map, char ch);
t_addr	ft_mapsize(char **map);
void	c3d_map_clear_check(char **map);
void	*c3d_map_clear_free(char **map);
int		c3d_map2vectors(t_opt *opt, t_scene *scene);
int		c3d_map2vectors_free(t_opt *opt, int errnum);
int		c3d_mlx_init(t_mlx *mlx);
int		c3d_mlx_loop(t_mlx *mlx);
int		c3d_mlx_hook(t_mlx *mlx);
int		c3d_win_init(t_mlx *mlx);
int		c3d_win_draw_vision(t_mlx *mlx);
void	c3d_win_draw_pixel(t_mlx *mlx, int x, int y, int color);
void	c3d_win_destroy(t_mlx *mlx);
int		c3d_img_init(t_mlx *mlx);
void	c3d_img_clear(t_img *img, int color_code, int width, int height);
void	c3d_img_destroy(t_mlx *mlx);
void	c3d_render_background(t_mlx *mlx);
void	c3d_render_visible(t_mlx *mlx);
void	c3d_render_intersect(t_mlx *mlx, int i_col, t_vec *ray);
void	c3d_render_vision(t_mlx *mlx);
void	c3d_render_hud_init(t_mlx *mlx);
void	c3d_render_hud(t_mlx *mlx);
void	c3d_render_elevation(t_mlx *mlx, t_coord *pt, int i_col, int tex_id);
void	c3d_render_blend(t_img *img_dst, t_img *img_src, t_addr *zero);
void	c3d_render_line(t_img *img, int color_code, \
	t_addr *zero, t_coord *line);
void	c3d_render_rectangle(t_img *img, int color_code, \
	t_addr *zero, t_addr *area);
void	c3d_render_imgpixel(t_img *img_dst, t_img *img_src, \
	t_addr *dst, t_addr *src);
void	c3d_render_imgline(t_img *img_dst, t_img *img_src, \
	t_addr *dst, t_addr *src);
void	c3d_game_init(t_game *game, t_scene *scene);
int		c3d_game_keyhook_down(int key, t_mlx *mlx);
int		c3d_game_keyhook_up(int key, t_mlx *mlx);
int		c3d_game_keyhook_fire(int key, t_mlx *mlx);
int		c3d_game_cursorhook(int x, int y, t_mlx *mlx);
int		c3d_game_clickhook(int button, int x, int y, t_mlx *mlx);
int		c3d_game_clickhook_up(int button, int x, int y, t_mlx *mlx);
bool	c3d_game_move(t_mlx *mlx, t_coord *move);
bool	c3d_game_turn(t_mlx *mlx, t_angle *turn);
bool	c3d_game_zoom(t_mlx *mlx, double fov_add);
bool	c3d_game_speed(int *new, int key, int old);
int		c3d_exit(int errnum);
int		c3d_exit_mlx(t_mlx *mlx, int errnum);
int		c3d_exit_mlx_break(t_mlx *mlx);
int		c3d_exit_mlx_goal(t_mlx *mlx);
int		c3d_print_err(int errnum);
void	c3d_print_control(void);
void	c3d_print_break(void);
char	c3d_idx2flag_direction(size_t idx);
int		ft_seterr(int errnum);
int		ft_seterr_return(int ret, int errnum);
void	*ft_seterr_null(int errnum);
void	*ft_free(void **p);
void	*ft_free_seterr(void **p, int errnum);
void	*ft_lstclear_seterr(t_list **lst, void (*del)(void*), int errnum);
int		ft_hasflag(int val, int flag);
bool	ft_stris(const char *str, int (*f)(int));
void	ft_coord_init(t_coord *pt);
void	ft_coord_set(t_coord *pt, double x, double y, double z);
void	ft_coord_copy(t_coord *dst, t_coord *src);
void	ft_addr_set(t_addr *addr, ssize_t x, ssize_t y);
bool	ft_inrange_dbl(double nb, double lower, double upper);

#endif
