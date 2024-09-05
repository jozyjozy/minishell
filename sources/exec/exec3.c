/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:02:49 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/10 12:16:20 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_pids	*last_pids(t_pids *pids)
{
	t_pids	*pids2;

	pids2 = malloc(sizeof(t_pids));
	if (!pids2)
		return (NULL);
	while (pids->next)
		pids = pids->next;
	pids->next = pids2;
	pids2->next = NULL;
	return (pids2);
}

char	*get_name_error(char	*str)
{
	int		i;
	int		j;
	char	**fdins;
	char	*str2;

	j = 0;
	fdins = ft_split_quote(str, ' ');
	while (fdins[j])
	{
		str2 = delete_quote(&fdins[j][1]);
		i = 0;
		if (fdins[j][0] == '<' && fdins[j][1] != '<')
			i = open(&fdins[j][1], O_RDONLY);
		if (i == -1)
		{
			return (ft_free_fdin(fdins), str2);
		}
		free(str2);
		if (i > 0)
			close(i);
		j++;
	}
	return (ft_free_fdin(fdins), NULL);
}

void	free_fds(int **fds, t_cmds *cmds)
{
	int	i;

	i = 0;
	while (cmds)
	{
		cmds = cmds->next;
		if (fds[i][0] > 1)
			close (fds[i][0]);
		if (fds[i][1] > 1)
			close (fds[i][1]);
		if (fds[i])
			free(fds[i]);
		else
			break ;
		i++;
	}
	free(fds);
}

void	free_pids(t_pids *pids)
{
	t_pids	*tmp;

	while (pids)
	{
		tmp = pids;
		pids = pids->next;
		free(tmp);
	}
}

void	wait_all(t_pids *pids)
{
	int		out;
	int		i;
	t_pids	*pids2;

	pids2 = pids;
	i = 0;
	while (pids->next != NULL)
	{
		waitpid(pids->pid, &out, 0);
		pids = pids->next;
		i++;
	}
	waitpid(pids->pid, &out, 0);
	i = out;
	if (WIFSIGNALED(out))
		WTERMSIG(i);
	else if (g_signal.exit_status != 1)
		g_signal.exit_status = WEXITSTATUS(i);
	free_pids(pids2);
}
