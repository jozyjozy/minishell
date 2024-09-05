/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:12:39 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/11 14:19:04 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_heredoc(char *str, t_data *data, int qot)
{
	char	*str2;
	int		pipefd[2];
	int		j;

	j = ft_strlen(str);
	if (pipe(pipefd) < 0)
		perror("pipe");
	g_signal.checker = 42;
	signal_controller(0);
	str2 = readline(">");
	while (str2)
	{
		if (ft_strncmp(str, str2, j) == 0)
			break ;
		if (qot == 0)
			str2 = ft_expand_heredoc(str2, data, 0);
		if (!str2)
			break ;
		ft_putstr_fd(str2, pipefd[1]);
		ft_putchar_fd('\n', pipefd[1]);
		free(str2);
		str2 = readline(">");
	}
	close(pipefd[1]);
	return (pipefd[0]);
}

int	not_here_doc(char *line, int i)
{
	int	chk;
	int	j;

	j = 0;
	chk = 1;
	while (line[j])
	{
		if (line[j] == '<' && line[j + 1] == '<')
		{
			j += 2;
			while (line[j] != '$' && line[j])
				j++;
			if (j == i)
				return (0);
		}
		j++;
	}
	return (1);
}
