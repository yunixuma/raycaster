/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_const.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/03/11 21:32:40 by Yoshihiro K      ###   ########.fr       */
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
# define ERR_ID				EFAULT
# define ERR_DUP			EEXIST
# define ERR_NOTNUM			EDOM
# define ERR_RANGE			ERANGE
# define ERR_MANYVALS		EOVERFLOW
# define ERR_NODEF			ENXIO
# define ERR_EMPTY			ENODATA
# define ERR_CHR			EINVAL
# define ERR_COUNT			EMLINK
# define ERR_OUTER			EILSEQ
//# define ERR_SHAPE			EMSGSIZE
//# define ERR_PATH			EHOSTUNREACH
# define ERR_MLX			EBUSY
//# define ERR_HUGE			EFBIG

# define UNIT_MOVE			0.03125
# define UNIT_TURN			1.
# define ANGLE_RIGHT		90.
# define ANGLE_FOV			90.
# define ANGLE_FOV_MAX		108.
# define ANGLE_FOV_MIN		72.
# define WIDTH_VISION		640
# define HEIGHT_VISION		480
# define ZERO_VISION		0
# define HEIGHT_SIGHT		0.5
# define WIDTH_BLOCK		120
# define HEIGHT_BLOCK		120
# define SIZE_CELL			12
# define LEN_POS			2
# define RATIO_HUD			3
# define WEIGHT_FRAME		2
# define UNIT_SPEED			1
# define MAX_SPEED			3

typedef enum e_channel
{
	IDX_ALPHA = 0,
	IDX_RED = 1,
	IDX_GREEN = 2,
	IDX_BLUE = 3,
	N_CHANNEL = 4
}	t_channel;

typedef enum e_surface
{
	IDX_FLOOR = 0,
	IDX_CEILING = 1,
	N_COLOR = 2
}	t_surface;

typedef enum e_chr
{
	IDX_NORTH = 0,
	IDX_EAST = 1,
	IDX_SOUTH = 2,
	IDX_WEST = 3,
	IDX_FREE = 4,
	IDX_WALL = 5,
	IDX_SPACE = 6,
	SIZE_CHRS_MAP = 7
}	t_chr;

# define N_DIRECTION		IDX_FREE
# define N_TEXTURE			N_DIRECTION

typedef enum e_imgidx
{
	IDX_VISION = N_TEXTURE,
	IDX_HUD = N_TEXTURE + 1,
	N_IMAGE = N_TEXTURE + 2
}	t_imgidx;

# define INVAL_FILENO		-1
# define VAL_INVAL			-1
# define CHR_DIR			'/'
# define CHR_SEP			','
# define CHR_SPACE			' '
# define COLOR_SPACE		0x7f000000
# define COLOR_WALL			0x3f00007f
# define COLOR_FREE			0x3fffffff
# define COLOR_POS			0x3fff0000
# define COLOR_FRAME		0x3f00ff00

# define FLAG_CHECKED		0x80
# define SIZE_NULL			0
# define POS_NOEXIST		-1
# define SIZE_TILE			64
# define SIZE_TILE_SMALL	32
# define SIZE_FRAME_SIDE	4
# define SIZE_FRAME_END		28
# define COLOR_OBJ			0x00FF0000

#endif
