/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/26 13:10:18 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROMPT_H
# define FT_PROMPT_H

# include <stdio.h>

# define PROMPT_CLEAR		"\033[2J"		// Clear the terminal
# define PROMPT_CLEAR_RIGHT	"\033[0K"		// Clear fr cursor to end of line
# define PROMPT_CLEAR_LEFT	"\033[1K"		// Clear fr cursor to head of line
# define PROMPT_CLEAR_LINE	"\033[2K"		// Clear the line
# define PROMPT_MOVE		"\033[%d;%dH"	// Move the cursor to
# define PROMPT_MOVE_RIGHT	"\033[%dC"		// Move the cursor right
# define PROMPT_MOVE_LEFT	"\033[%dD"		// Move the cursor left
# define PROMPT_MOVE_DOWN	"\033[%dB"		// Move the cursor down
# define PROMPT_MOVE_UP		"\033[%dA"		// Move the cursor up

int	ft_prompt_clr(void);
int	ft_prompt_clr_line(void);
int	ft_prompt_clr_left(void);
int	ft_prompt_clr_right(void);
int	ft_prompt_arg(const char *s, int n);
int	ft_prompt_arg_2(const char *s, int n1, int n2);

#endif
