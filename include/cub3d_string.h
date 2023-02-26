/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/27 06:23:56 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRING_H
# define CUB3D_STRING_H

# define CHRS_MAP			"NSEW01 "
# define STR_EMPTY			""
# define STR_EXT			".cub"
# define STR_TITLE			"cub3D"
# define STR_ON				"ON"
# define STR_OFF			"OFF"
# define ID_NORTH			"NO "
# define ID_SOUTH			"SO "
# define ID_EAST			"EA "
# define ID_WEST			"WE "
# define ID_FLOOR			"F "
# define ID_CEILING			"C "

# define MSG_ERR			"Error"
# define MSG_NOARG			"Missing the argument to specify a map file"
# define MSG_MANYARGS		"Please specify only one argument"
# define MSG_FEXT			"File extention of map file must be \".cub\""
# define MSG_FPATH			"The file path is too long"
# define MSG_OPEN			"Cannot open the file"
# define MSG_ALLOC			"An error occured during allocating memory"
# define MSG_EMPTY			"Empty line appeared"
# define MSG_CHR			"Invalid character contained"
# define MSG_SHAPE			"The map must be rectangular"
# define MSG_COUNT			"Too many or too few characters contained"
# define MSG_OUTER			"The map must be surrounded by walls"
# define MSG_PATH			"No route to the exit and/or some collectibles"
# define MSG_HUGE			"The map is too large to display"
# define MSG_MLX			"An error occured during initiate a X-Window I/F"
# define MSG_WAIT			"Wait a moment for creating the window..."
//# define MSG_HOWTO_GOAL	"Control the monkey to take all stars to dragon"
# define MSG_HOWTO_MOVE		"Move: [W][A][S][D]\nTurn: [Left][Right]"
# define MSG_HOWTO_TURN		"Focus: [LeftClick]\nScroll: [MidClick]"
# define MSG_HOWTO_ZOOM		"Zoom-in: [PgUp][ScrUp]\tZoom-out: [PgDn][ScrDn]"
# define MSG_HOWTO_SPEED	"Change Speed: [F][RightClick]"
# define MSG_HOWTO_EXIT		"Exit: [Q] or [Esc]"
# define MSG_STATUS_POS		"Coord: (%6.2lf, %5.2lf)\tAzimuth: %6.1lf\n"
# define MSG_STATUS_MODE	"Speed: %d\tFOV: %3.0lf\tCursor: %s\n"
//# define MSG_SCORE			"Player %3d scores moved\n"
# define MSG_BREAK			"Terminated by player's operation"
# define MSG_GOAL			"Congratulations (%3d pts in the end)"

#endif
