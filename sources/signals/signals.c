/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:05:24 by jlarue            #+#    #+#             */
/*   Updated: 2023/05/22 14:53:44 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signal_controller(int i)
{
	if (i == 0)
	{
		signal(SIGINT, sig_int);
		if (g_signal.checker == 0 || g_signal.checker == 42)
			signal(SIGQUIT, SIG_IGN);
		else if (g_signal.checker != 0)
			signal(SIGQUIT, sig_quit);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	*ft_memdel(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (NULL);
}

void	sig_int(int code)
{
	(void)code;
	ft_putstr_fd("\n", 2);
	if (g_signal.pid != 0)
		g_signal.exit_status = SCRIPT_ENDED_CTRL_C;
	if (g_signal.checker == 42)
	{
		g_signal.exit_status = SCRIPT_ENDED_CTRL_C;
		close(0);
	}
	else if (g_signal.pid == 0 && g_signal.checker == 0)
	{
		g_signal.exit_status = SCRIPT_ENDED_CTRL_C;
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_signal.exit_status = SCRIPT_ENDED_CTRL_C;
	g_signal.sigint = 1;
}

void	sig_quit(int code)
{
	printf("%d\n", g_signal.pid);
	if (g_signal.pid == 0)
	{
		ft_putstr_fd("Quit (core dumped)\n", 2);
		g_signal.sigquit = 1;
	}
	g_signal.exit_status = FATAL_ERROR_NEEDS_ADD + code;
}

void	sig_init(int mode)
{
	g_signal.sigint = 0;
	g_signal.sigquit = 0;
	g_signal.pid = 0;
	if (mode == 0)
		g_signal.exit_status = 0;
	g_signal.checker = 0;
}
