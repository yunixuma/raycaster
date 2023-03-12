/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/03/12 21:38:15 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_print_err_sub(int errnum)
{
	if (errnum == ERR_NOTNUM)
		ft_putendl_fd(MSG_NOTNUM, STDERR_FILENO);
	else if (errnum == ERR_RANGE)
		ft_putendl_fd(MSG_RANGE, STDERR_FILENO);
	else if (errnum == ERR_MANYVALS)
		ft_putendl_fd(MSG_NODEF, STDERR_FILENO);
	else if (errnum == ERR_NODEF)
		ft_putendl_fd(MSG_MANYVALS, STDERR_FILENO);
	else if (errnum == ERR_EMPTY)
		ft_putendl_fd(MSG_EMPTY, STDERR_FILENO);
	else if (errnum == ERR_CHR)
		ft_putendl_fd(MSG_CHR, STDERR_FILENO);
	else if (errnum == ERR_COUNT)
		ft_putendl_fd(MSG_COUNT, STDERR_FILENO);
	else if (errnum == ERR_OUTER)
		ft_putendl_fd(MSG_OUTER, STDERR_FILENO);
	else if (errnum == ERR_MLX)
		ft_putendl_fd(MSG_MLX, STDERR_FILENO);
	return (errnum);
}

//	else if (errnum == ERR_SHAPE)
//		ft_putendl_fd(MSG_SHAPE, STDERR_FILENO);
//	else if (errnum == ERR_PATH)
//		ft_putendl_fd(MSG_PATH, STDERR_FILENO);
//	else if (errnum == ERR_HUGE)
//		ft_putendl_fd(MSG_HUGE, STDERR_FILENO);

int	c3d_print_err(int errnum)
{
	if (errnum)
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
	ft_putstr_fd(PROMPT_WARN, STDERR_FILENO);
	if (errnum == ERR_NOARG)
		ft_putendl_fd(MSG_NOARG, STDERR_FILENO);
	else if (errnum == ERR_MANYARGS)
		ft_putendl_fd(MSG_MANYARGS, STDERR_FILENO);
	else if (errnum == ERR_FEXT)
		ft_putendl_fd(MSG_FEXT, STDERR_FILENO);
	else if (errnum == ERR_FPATH)
		ft_putendl_fd(MSG_FPATH, STDERR_FILENO);
	else if (errnum == ERR_OPEN)
		ft_putendl_fd(MSG_OPEN, STDERR_FILENO);
	else if (errnum == ERR_ALLOC)
		ft_putendl_fd(MSG_ALLOC, STDERR_FILENO);
	else if (errnum == ERR_ID)
		ft_putendl_fd(MSG_ID, STDERR_FILENO);
	else if (errnum == ERR_DUP)
		ft_putendl_fd(MSG_DUP, STDERR_FILENO);
	else
		c3d_print_err_sub(errnum);
	return (errnum);
}

void	c3d_print_control(void)
{
	ft_putendl_fd(MSG_HOWTO_MOVE, STDOUT_FILENO);
	ft_putendl_fd(MSG_HOWTO_TURN, STDOUT_FILENO);
	ft_putendl_fd(MSG_HOWTO_FOCUS, STDOUT_FILENO);
	ft_putendl_fd(MSG_HOWTO_SCROLL, STDOUT_FILENO);
	ft_putendl_fd(MSG_HOWTO_ZOOMIN, STDOUT_FILENO);
	ft_putendl_fd(MSG_HOWTO_ZOOMOUT, STDOUT_FILENO);
	ft_putendl_fd(MSG_HOWTO_SPEED, STDOUT_FILENO);
	ft_putendl_fd(MSG_HOWTO_EXIT, STDOUT_FILENO);
	ft_putendl_fd(MSG_HLINE, STDOUT_FILENO);
}

void	c3d_print_status(t_game *game)
{
	const char	*cursor_mode[2] = {STR_OFF, STR_ON};

	if (ft_hasflag(game->event, FLAG_INIT))
		game->event &= ~FLAG_INIT;
	else
	{
		ft_prompt_arg(PROMPT_MOVE_UP, 1);
		ft_prompt_clr_line();
		ft_prompt_arg(PROMPT_MOVE_UP, 1);
		ft_prompt_clr_line();
	}
	printf(MSG_STATUS_POS_1, game->coord.x);
	printf(MSG_STATUS_POS_2, game->coord.y);
	printf(MSG_STATUS_ANGLE, game->angle.yaw);
	printf(MSG_STATUS_SPEED, game->speed);
	printf(MSG_STATUS_FOV, game->fov);
	printf(MSG_STATUS_MODE, cursor_mode[ft_hasflag(game->event, FLAG_CURSOR)]);
}

void	c3d_print_break(void)
{
	ft_putendl_fd(MSG_BREAK, STDOUT_FILENO);
}

/*
void	c3d_print_score(int score)
{
	printf(MSG_SCORE, score);
}
*/
/*
void	c3d_print_goal(int score)
{
	printf(MSG_GOAL, score);
}
*/