/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:12:09 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/11 10:39:18 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_start_opt(t_cmds *cmds)
{
	int	i;
	int	j;

	i = 1;
	while (cmds->opt[i])
	{
		j = 1;
		if (cmds->opt[i][0] == '-')
		{
			while (cmds->opt[i][j] == 'n' && cmds->opt[i][j])
				j++;
		}
		else
			break ;
		if (cmds->opt[i][j] != '\0')
			break ;
		i++;
	}
	return (i - 1);
}

void	ft_printf_echo(t_cmds *cmds, int chk)
{
	int	i;
	int	j;

	j = 0;
	i = ft_start_opt(cmds);
	while (cmds->opt[++i])
	{
		j = printf("%s", cmds->opt[i]);
		if (cmds->opt[i + 1])
			printf(" ");
		if (j == -1)
			break ;
	}
	if (chk != 0 && j != -1)
		j = printf("\n");
	if (j == -1)
	{
		write(2, "Minishell: echo: write error: no space left on device\n", 55);
		g_signal.exit_status = GENERAL_ERROR;
	}
	else
		g_signal.exit_status = 0;
}

void	ft_echo(t_cmds *cmds)
{
	int	i;
	int	chk;

	i = 1;
	chk = 1;
	g_signal.exit_status = 0;
	if (cmds->opt[1])
	{
		if (cmds->opt[1][0] == '-')
		{
			while (cmds->opt[1][i] == 'n' && cmds->opt[1][i])
				i++;
			if (cmds->opt[1][i] == '\0')
				chk = 0;
		}
	}
	ft_printf_echo(cmds, chk);
}
