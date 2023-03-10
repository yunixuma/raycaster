/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_flag.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/26 22:56:10 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_FLAG_H
# define CUB3D_FLAG_H

# define FLAG_NONE		'\x00'
# define FLAG_START		'\x10'
# define FLAG_FREE		'\x20'
# define FLAG_WALL		'\x40'
# define FLAG_SPACE		'\x80'
# define FLAG_NORTH		'\x01'
# define FLAG_EAST		'\x02'
# define FLAG_SOUTH		'\x04'
# define FLAG_WEST		'\x08'

# define FLAG_NOEVENT	0x00
# define FLAG_INIT		0x01
# define FLAG_PROMPT	0x02
# define FLAG_DRAW		0x04
# define FLAG_KEY		0x20
# define FLAG_CURSOR	0x40
# define FLAG_CLICK		0x80

#endif
