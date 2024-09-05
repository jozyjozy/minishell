/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 05:07:57 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/09 11:06:34 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_pars(t_cmds *cmds, char **cmd, char *str)
{
	if (str)
		free(str);
	if (cmds)
		ft_lstclear_cmd(cmds);
	free_tab_fc(cmd);
	write(2, "Error Malloc\n", 14);
}

int	check_cmds(t_cmds *cmds)
{
	while (cmds)
	{
		if (!cmds->cmd)
			return (1);
		if (!cmds->in)
			return (1);
		if (!cmds->out)
			return (1);
		if (!cmds->opt)
			return (1);
		cmds = cmds->next;
	}
	return (0);
}

void	sus(t_data *data, int i)
{
	write(2, "Error Malloc\n", 14);
	free(data);
	exit(i);
}

void	ft_free_rdc(t_cmds *cmds)
{
	if (cmds->in)
		free(cmds->in);
	if (cmds->out)
		free(cmds->out);
}
