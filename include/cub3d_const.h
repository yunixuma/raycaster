/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_const.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/10 18:27:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CONST_H
# define CUB3D_CONST_H

# include <stdint.h>
# include <errno.h>

# define OFFSET_ARG			1
# define IDX_ARG			1
# define LEN_MAXPATH		255
# define BITS_CHANNEL		8
# define MASK_CHANNEL		0xff
# define ERR_NOERR			0
# define ERR_NOARG			EISDIR
# define ERR_MANYARGS		E2BIG
# define ERR_FEXT			ENOEXEC
# define ERR_FPATH			ENAMETOOLONG
# define ERR_OPEN			ENOENT
# define ERR_ALLOC			ENOMEM
# define ERR_DUP			EEXIST
# define UNIT_MOVE			0.125
# define UNIT_TURN			3.
# define ANGLE_RIGHT		90.
# define ANGLE_FOV			90.
# define ANGLE_FOV_MAX		108.
# define ANGLE_FOV_MIN		72.
# define WIDTH_VISION		720
# define HEIGHT_VISION		480
# define ZERO_VISION		0
# define HEIGHT_SIGHT		0.5
# define WIDTH_BLOCK		120
# define HEIGHT_BLOCK		120
# define SIZE_CELL			12
# define RATIO_HUD			4
# define WEIGHT_FRAME		2

typedef enum e_channel
{
	IDX_RED,
	IDX_GREEN,
	IDX_BLUE,
	N_CHANNEL
}	t_channel;

typedef enum e_surface
{
	IDX_FLOOR,
	IDX_CEILING,
	N_COLOR
}	t_surface;

typedef enum e_chr
{
	IDX_NORTH,
	IDX_EAST,
	IDX_SOUTH,
	IDX_WEST,
	IDX_FREE,
	IDX_WALL,
	IDX_SPACE,
	SIZE_CHRS_MAP
}	t_chr;

# define N_DIRECTION		IDX_FREE
# define N_TEXTURE			N_DIRECTION

typedef enum e_imgidx
{
	IDX_VISION = N_TEXTURE,
	IDX_HUD,
	N_IMAGE
}	t_imgidx;

# define VAL_INVAL			-1
# define CHR_DIR			'/'
# define CHR_SEP			','
# define CHR_SPACE			' '
# define COLOR_SPACE		0x7f000000
# define COLOR_WALL			0x3f00007f
# define COLOR_FREE			0x3fffffff
# define COLOR_POS			0x3fff0000
# define COLOR_FRAME		0x3f00ff00

# define ERR_EMPTY			ENODATA
# define ERR_CHR			EINVAL
# define ERR_SHAPE			EMSGSIZE
# define ERR_COUNT			EMLINK
# define ERR_OUTER			EILSEQ
# define ERR_PATH			EHOSTUNREACH
# define ERR_HUGE			EFBIG
# define FLAG_CHECKED		0x80
# define SIZE_NULL			0
# define POS_NOEXIST		-1
# define SIZE_TILE			64
# define SIZE_TILE_SMALL	32
# define SIZE_FRAME_SIDE	4
# define SIZE_FRAME_END		28
# define COLOR_OBJ			0x00FF0000

#endif
