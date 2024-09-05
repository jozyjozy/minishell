/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:58:52 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/02 15:48:21 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_data(t_cmds *cmds)
{
	int	i;
	int	j;

	i = 1;
	while (cmds != NULL)
	{
		j = -1;
		printf("cmd %d\n", i);
		printf("cmd = %s\n", cmds->cmd);
		printf("in = %s\n", cmds->in);
		printf("out = %s\n", cmds->out);
		while (cmds->opt[++j])
			printf("opt %d = %s\n", (j + 1), cmds->opt[j]);
		printf("next = %p\n", cmds->next);
		printf("\n");
		cmds = cmds->next;
		i++;
	}
}

void	ft_lstclear_cmd(t_cmds *cmds)
{
	t_cmds	*tmp;
	int		i;

	while (cmds != NULL)
	{
		i = -1;
		if (cmds->cmd)
			free(cmds->cmd);
		if (cmds->opt)
		{
			while (cmds->opt[++i])
				free(cmds->opt[i]);
			free(cmds->opt);
		}
		if (cmds->in)
			free(cmds->in);
		if (cmds->out)
			free(cmds->out);
		tmp = cmds;
		cmds = cmds->next;
		free(tmp);
	}
}

int	lst_cmd_mid(char *str, t_cmds *cmds)
{
	while (cmds->next != NULL)
		cmds = cmds->next;
	cmds->next = first_cmds(str);
	if (cmds->next == NULL)
		return (1);
	return (0);
}

char	*fill_str_redirect(char *str, char *tabtab)
{
	char	*str2;

	if (str)
	{
		str2 = ft_strjoin(str, " ");
		free(str);
		str = ft_strjoin(str2, tabtab);
		free(str2);
	}
	else
		str = ft_strjoin(tabtab, "");
	return (str);
}

void	free_tab_fc(char **tabtab)
{
	int	i;

	i = 0;
	while (tabtab[i])
		free(tabtab[i++]);
	free(tabtab);
}
