/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_event.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/09 02:44:26 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_EVENT_H
# define CUB3D_EVENT_H

# define EVENT_KEYDOWN		2
# define EVENT_MOUSEMOVE	6
# define EVENT_EXPOSE		12
# define EVENT_DESTROY		17
# define MASK_STRUCT		1

# define KEYCODE_Q		'q'
# define KEYCODE_W		'w'
# define KEYCODE_A		'a'
# define KEYCODE_S		's'
# define KEYCODE_D		'd'
# define KEYCODE_UP		0xff52
# define KEYCODE_LEFT	0xff51
# define KEYCODE_DOWN	0xff54
# define KEYCODE_RIGHT	0xff53
# define KEYCODE_ESC	0xff1b
# define KEYCODE_PGUP	0xff55
# define KEYCODE_PGDN	0xff56
# define KEY_EXIT_1		KEYCODE_ESC
# define KEY_EXIT_2		KEYCODE_Q
# define KEY_FORWARD	KEYCODE_W
# define KEY_BACKWARD	KEYCODE_S
# define KEY_MOVELEFT	KEYCODE_A
# define KEY_MOVERIGHT	KEYCODE_D
# define KEY_TURNLEFT	KEYCODE_LEFT
# define KEY_TURNRIGHT	KEYCODE_RIGHT
# define KEY_LOOKUP		KEYCODE_UP
# define KEY_LOOKDOWN	KEYCODE_DOWN
# define KEY_TELE		KEYCODE_PGUP
# define KEY_WIDE		KEYCODE_PGDN
# define KEY_NONE		0x7fffffffL

#endif
