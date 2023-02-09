/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_event_mac.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/09 09:02:48 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_EVENT_MAC_H
# define CUB3D_EVENT_MAC_H

# define EVENT_KEYDOWN	2
# define EVENT_EXPOSE	12
# define EVENT_DESTROY	17
# define MASK_STRUCT	1

# define KEYCODE_Q		0x0c
# define KEYCODE_W		0x0d
# define KEYCODE_A		0x00
# define KEYCODE_S		0x01
# define KEYCODE_D		0x02
# define KEYCODE_UP		0x7e
# define KEYCODE_LEFT	0x7b
# define KEYCODE_DOWN	0x7d
# define KEYCODE_RIGHT	0x7c
# define KEYCODE_ESC	0x35
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
# define KEY_TELE		KEYCODE_PAGEUP
# define KEY_WIDE		KEYCODE_PAGEDOWN
# define KEY_NONE		0x7fffffffL

#endif
