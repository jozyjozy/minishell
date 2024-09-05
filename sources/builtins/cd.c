/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:24:09 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/12 10:04:53 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	go_to_home(char *str)
{
	DIR		*dir;

	dir = opendir(&str[5]);
	chdir(&str[5]);
	if (g_signal.checker == 0 && dir == NULL)
	{
		g_signal.exit_status = 1;
		perror(&str[5]);
	}
	if (dir)
	{
		g_signal.exit_status = 0;
		closedir(dir);
	}
}

void	check_home(t_data *data)
{
	int	i;

	i = 0;
	while (data->ms_env[i])
	{
		if (ft_strncmp(data->ms_env[i], "HOME=", 5) == 0)
		{
			go_to_home(data->ms_env[i]);
			return ;
		}
		i++;
	}
	if (!(data->ms_env[i]) && g_signal.checker == 0)
		printf("Minishell: cd: HOME not set\n");
	return ;
}

void	ft_cd(t_cmds *cmds, t_data *data)
{
	DIR		*dir;

	if (!(cmds->opt[1]))
		return (check_home(data));
	if (cmds->opt[2] && g_signal.checker == 0)
	{
		write(2, "Too many argument\n", 19);
		g_signal.exit_status = 1;
		return ;
	}
	dir = opendir(cmds->opt[1]);
	chdir(cmds->opt[1]);
	if (g_signal.checker == 0 && dir == NULL)
	{
		g_signal.exit_status = 1;
		perror(cmds->opt[1]);
	}
	if (dir)
	{
		g_signal.exit_status = 0;
		closedir(dir);
		do_pwd(data);
	}
}
