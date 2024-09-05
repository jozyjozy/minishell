/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:16:26 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/08 15:53:00 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_builtins(t_cmds *cmds, t_data	*data)
{
	if (ft_strncmp(cmds->cmd, "echo\0", 5) == 0)
		return (ft_echo(cmds), 1);
	if (ft_strncmp(cmds->cmd, "cd\0", 3) == 0)
		return (ft_cd(cmds, data), 1);
	if (ft_strncmp(cmds->cmd, "pwd\0", 4) == 0)
		return (ft_pwd(cmds), 1);
	if (ft_strncmp(cmds->cmd, "export\0", 7) == 0)
		return (ft_export(cmds, data), 1);
	if (ft_strncmp(cmds->cmd, "unset\0", 6) == 0)
		return (ft_unset(data, cmds), 1);
	if (ft_strncmp(cmds->cmd, "exit\0", 5) == 0)
		return (1);
	if (ft_strncmp(cmds->cmd, "env\0", 4) == 0)
		return (ft_env(data, cmds), 1);
	return (0);
}

void	ft_is_builtins2(t_cmds *cmds, t_data *data)
{
	if (ft_strncmp(cmds->cmd, "cd\0", 3) == 0)
		ft_cd(cmds, data);
	if (ft_strncmp(cmds->cmd, "export\0", 7) == 0)
		ft_export(cmds, data);
	if (ft_strncmp(cmds->cmd, "unset\0", 6) == 0)
		ft_unset(data, cmds);
	if (ft_strncmp(cmds->cmd, "exit\0", 5) == 0)
		ft_exit(data, cmds);
}
