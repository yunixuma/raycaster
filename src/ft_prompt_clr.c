/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_clr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/26 13:08:38 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_prompt.h"

int	ft_prompt_clr(void)
{
	return (printf(PROMPT_CLEAR));
}

int	ft_prompt_clr_line(void)
{
	return (printf(PROMPT_CLEAR_LINE));
}

int	ft_prompt_clr_left(void)
{
	return (printf(PROMPT_CLEAR_LEFT));
}

int	ft_prompt_clr_right(void)
{
	return (printf(PROMPT_CLEAR_RIGHT));
}
