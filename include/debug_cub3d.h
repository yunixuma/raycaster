/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_cub3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/17 14:54:23 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_CUB3D_H
# define DEBUG_CUB3D_H

# include "libft.h"
# include "debug_common.h"
# include "cub3d_const.h"
# include "cub3d_typedef.h"

void	debug_c3d_lst(t_list *lst);
void	debug_c3d_game(t_game *game);
void	debug_c3d_scene(t_scene *scene);
void	debug_c3d_countchr(int *arr);
void	debug_c3d_map_raw(char **map);
void	debug_c3d_map_flag(char **map);
void	debug_c3d_img(t_img img, int size_tile);
void	debug_c3d_f_angle(t_angle *angle);
void	debug_c3d_f_coord(t_coord *coord);
void	debug_c3d_f_vec(t_vec *vec);
void	debug_c3d_f_vecs(t_opt *opt);

#endif
