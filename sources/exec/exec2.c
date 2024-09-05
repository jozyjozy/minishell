/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:29:32 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/22 15:16:14 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	wait_and_check(t_cmds *cmds, t_pids *pids, t_data *data)
{
	int		in;
	int		out;

	while (cmds)
	{
		in = check_fdin(cmds->in, 1, data);
		if (in < 0)
		{
			if (cmds->next == NULL)
					g_signal.exit_status = 1;
			perrorms(cmds);
		}
		out = check_fdout2(cmds->out);
		if (out < 0)
		{
			if (cmds->next == NULL)
					g_signal.exit_status = 1;
			perrorms2(cmds);
		}
		close(out);
		close(in);
		cmds = cmds->next;
	}
	wait_all(pids);
}

char	*get_access(char *str1, char *env)
{
	char	*str;
	char	*cmd;
	int		i;

	i = 0;
	str = str1;
	if (str1[0] && (access(str, F_OK) == -1 || access(str, X_OK) == -1) && env)
	{
		cmd = malloc(sizeof(char) * (ft_strlen(str) + 2));
		if (!cmd)
			return (NULL);
		cmd[i] = '/';
		while (str[i])
		{
			cmd[i + 1] = str[i];
			i++;
		}
		cmd[i + 1] = '\0';
		str = get_valid_path(env, cmd);
		if (!str)
			return (free(cmd), str1);
		return (str);
	}
	return (str1);
}

void	exv(t_cmds *cmds, t_data *data)
{
	char	*str;

	if (ft_is_builtins(cmds, data) == 1)
		return ;
	str = get_access(cmds->cmd, get_path(data->ms_env));
	if (!str)
		return ;
	if (execve(str, cmds->opt, data->ms_env) < 0)
	{
		write(2, "Minishell: ", 12);
		write(2, cmds->cmd, ft_strlen(cmds->cmd));
		write(2, ": command not found\n", 21);
		g_signal.exit_status = CMD_NOT_FOUND;
	}
}

void	parent_redirect(int	*pipefd)
{
	close(pipefd[1]);
	if (dup2(pipefd[0], 0) < 0)
		perror("dup2");
	close(pipefd[0]);
}

int	redirect(t_cmds *cmds, int *fd, t_pids *pids)
{
	int		pipefd[2];

	if (pipe(pipefd) < 0)
		perror("pipe");
	if (pids->pid)
		pids = last_pids(pids);
	if (!pids)
		return (0);
	pids->pid = fork();
	if (pids->pid < 0)
		perror("fork");
	else if (pids->pid != 0)
	{
		parent_redirect(pipefd);
		return (1);
	}
	else
	{
		if (child_redirect(pipefd, fd, cmds) == 0)
			return (2);
		return (0);
	}
	return (1);
}
