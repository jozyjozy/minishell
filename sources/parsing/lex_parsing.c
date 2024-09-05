/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:30:33 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/12 10:24:28 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_trim_rdc(char *str)
{
	char	*str2;

	str2 = ft_strnstr(str, "< ", ft_strlen(str));
	if (str2)
		memmove(str2 + 1, str2 + 2, ft_strlen(str2 + 2) + 1);
	while (str2)
	{
		str2 = ft_strnstr(str, "< ", ft_strlen(str));
		if (str2)
			memmove(str2 + 1, str2 + 2, ft_strlen(str2 + 2) + 1);
	}
	str2 = ft_strnstr(str, "> ", ft_strlen(str));
	if (str2)
		memmove(str2 + 1, str2 + 2, ft_strlen(str2 + 2) + 1);
	while (str2)
	{
		str2 = ft_strnstr(str, "> ", ft_strlen(str));
		if (str2)
			memmove(str2 + 1, str2 + 2, ft_strlen(str2 + 2) + 1);
	}
}

pid_t	do_execv(t_cmds *cmds, t_data *data)
{
	int		out;
	t_cmds	*tmp;

	tmp = cmds;
	if (check_cmds(cmds) == 1)
		return (ft_lstclear_cmd(cmds), 1);
	g_signal.checker = 1;
	g_signal.pid = fork();
	if (!g_signal.pid)
	{
		g_signal.exit_status = 0;
		exec_cmd(cmds, data);
	}
	if (g_signal.pid)
	{
		signal_controller(1);
		g_signal.checker = 0;
		waitpid(g_signal.pid, &out, 0);
		g_signal.exit_status = WEXITSTATUS(out);
		while (cmds->next)
			cmds = cmds->next;
		if (!tmp->next)
			ft_is_builtins2(cmds, data);
	}
	return (ft_lstclear_cmd(tmp), g_signal.pid);
}

pid_t	pars(char **cmd, t_data *data)
{
	int			i;
	t_cmds		*cmds;
	char		*str;
	long long	w;

	i = -1;
	cmds = NULL;
	w = 0;
	while (cmd[++i])
	{
		ft_trim_rdc(cmd[i]);
		str = ft_expand(cmd[i], data, w);
		if (i == 0)
		{
			cmds = first_cmds(str);
			if (!cmds)
				return (ft_free_pars(cmds, cmd, str), 1);
		}
		else if (lst_cmd_mid(str, cmds) == 1)
			return (ft_free_pars(cmds, cmd, str), 1);
		free(str);
	}
	free_tab_fc(cmd);
	return (do_execv(cmds, data));
}

int	check_syntax(char *line)
{
	int	chk;

	chk = 0;
	chk += check_pipe(line, 1, 1);
	chk += check_quote(line);
	chk += check_angle_brackets(line);
	return (chk);
}

pid_t	lex_pars(char *line, t_data *data)
{
	char	**tabtab;
	pid_t	pid;

	if (check_syntax(line) != 0)
	{
		g_signal.exit_status = 2;
		write(2, "syntax error\n", 14);
		return (1);
	}
	if (line[0] == '!' && line[1] == '\0')
	{
		g_signal.exit_status = 1;
		return (1);
	}
	tabtab = ft_split_quote(line, '|');
	pid = pars(tabtab, data);
	g_signal.pid = pid;
	return (pid);
}
