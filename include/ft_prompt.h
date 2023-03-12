/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/03/12 15:56:17 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROMPT_H
# define FT_PROMPT_H

# include <stdio.h>

# define ANSI_BLACK				0				// ANSI color index black
# define ANSI_RED				1				// ANSI color index red
# define ANSI_GREEN				2				// ANSI color index green
# define ANSI_YELLOW			3				// ANSI color index yellow
# define ANSI_BLUE				4				// ANSI color index blue
# define ANSI_MAGENTA			5				// ANSI color index magenta
# define ANSI_CYAN				6				// ANSI color index cyan
# define ANSI_WHITE				7				// ANSI color index white
# define PROMPT_CLEAR			"\033[2J"		// Clear the terminal
# define PROMPT_CLEAR_RIGHT		"\033[0K"		// Clear to end of line
# define PROMPT_CLEAR_LEFT		"\033[1K"		// Clear to head of line
# define PROMPT_CLEAR_LINE		"\033[2K"		// Clear the line
# define PROMPT_MOVE_UP			"\033[%dA"		// Move the cursor up
# define PROMPT_MOVE_DOWN		"\033[%dB"		// Move the cursor down
# define PROMPT_MOVE_RIGHT		"\033[%dC"		// Move the cursor right
# define PROMPT_MOVE_LEFT		"\033[%dD"		// Move the cursor left
# define PROMPT_MOVE			"\033[%d;%dH"	// Move the cursor to
# define PROMPT_COLOR			"\033[3%dm"		// Change text color
# define PROMPT_COLOR_EXTEND	"\033[38;5;%dm"	// Change text color index
# define PROMPT_RESET_TEXT		"\033[39m"		// Reset text color
# define PROMPT_COLOR_BG		"\033[4%dm"		// Change bgcolor
# define PROMPT_COLOR_BG_EXTEND	"\033[48;5;%dm"	// Change bgcolor extend
# define PROMPT_RESET_BG		"\033[49m"		// Reset bgcolor
# define PROMPT_WARN			"\033[31m"		// Change text color
# define PROMPT_BOLD			"\033[1m"		// Change style bold
# define PROMPT_SHADE			"\033[2m"		// Change color shade 
# define PROMPT_ITALIC			"\033[3m"		// Change style italic
# define PROMPT_UNDERLINE		"\033[4m"		// Change style underline
# define PROMPT_BLINK			"\033[5m"		// Blink
# define PROMPT_INVERT			"\033[7m"		// Invert colors
# define PROMPT_HIDE			"\033[8m"		// Hide output
# define PROMPT_STRIKETHROUGH	"\033[9m"		// Change style strikethrough
# define PROMPT_RESET			"\033[0m"		// Reset style

int	ft_prompt_clr(void);
int	ft_prompt_clr_line(void);
int	ft_prompt_clr_left(void);
int	ft_prompt_clr_right(void);
int	ft_prompt_arg(const char *s, int n);
int	ft_prompt_arg_2(const char *s, int n1, int n2);

#endif
