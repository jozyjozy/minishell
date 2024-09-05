/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:04:59 by jlarue            #+#    #+#             */
/*   Updated: 2023/03/24 13:39:51 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	*get_valid_path(char *env, char *cmd)
{
	char	**path;
	char	*str;
	int		i;

	if (env == NULL)
		return (NULL);
	path = ft_split(&env[5], ':');
	i = 0;
	while (path[i])
	{
		str = ft_strjoin(path[i], cmd);
		if (access(str, F_OK) != -1)
			return (free(path), str);
		i++;
		free(str);
	}
	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
	return (NULL);
}

int	child_redirect(int *pipefd, int *fd, t_cmds *cmds)
{
	dup2(fd[0], 0);
	if (fd[1] == 1 && cmds->next)
		dup2(pipefd[1], 1);
	else if (fd[1] > 0)
		dup2(fd[1], 1);
	if (fd[1] > 0 && fd[1] != 1)
		close(fd[1]);
	if (fd[0] > 0 && fd[0] != 0)
		close(fd[0]);
	if (pipefd[1])
		close(pipefd[1]);
	if (pipefd[0])
		close(pipefd[0]);
	if (fd[0] == -1 || fd[1] == -1)
		return (1);
	return (0);
}

int	do_cmds(t_cmds *cmds, t_data *data, t_pids *pids, int **fd)
{
	int		i;
	int		j;
	t_cmds	*tmp;

	tmp = cmds;
	i = 0;
	while (cmds)
	{
		j = redirect(cmds, fd[i++], pids);
		if (j == 0)
			return (free_pids(pids), free_fds(fd, tmp), 1);
		if (j == 2)
		{
			free_fds(fd, tmp);
			exv(cmds, data);
			free_pids(pids);
			return (1);
		}
		cmds = cmds->next;
	}
	return (0);
}

void	exec_cmd(t_cmds *cmds, t_data *data)
{
	int		**fd;
	t_pids	*pids;
	t_cmds	*tmp;

	tmp = cmds;
	pids = malloc(sizeof(t_pids));
	if (!pids)
		return ;
	pids->next = NULL;
	pids->pid = 0;
	signal_controller(check_if_mini(cmds));
	fd = check_fd(cmds, data);
	if (g_signal.exit_status == SCRIPT_ENDED_CTRL_C)
		return (free_pids(pids), free_fds(fd, tmp));
	if (do_cmds(cmds, data, pids, fd) == 1)
		return ;
	free_fds(fd, tmp);
	wait_and_check(tmp, pids, data);
	return ;
}
