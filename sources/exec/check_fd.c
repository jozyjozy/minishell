/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:52:15 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/12 11:39:15 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	len_cmds_lst(t_cmds *cmds)
{
	int	i;

	i = 0;
	while (cmds)
	{
		i++;
		cmds = cmds->next;
	}
	return (i);
}

int	check_fdout2(char *str)
{
	int		i;
	int		j;
	char	**fdouts;
	char	*str2;

	j = -1;
	fdouts = ft_split_quote(str, ' ');
	while (fdouts[++j])
	{
		str2 = delete_quote(fdouts[j]);
		if (str2[0] == '>' && str2[1] == '>')
			i = open(&str2[2], O_WRONLY | O_CREAT | O_APPEND, 0777);
		else
			i = open(&str2[1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		free(str2);
		if (i < 0)
			return (ft_free_fdout(fdouts), i);
		if (i > 1)
			close(i);
	}
	return (ft_free_fdout(fdouts), 1);
}

char	*get_name_error2(char	*str)
{
	int		i;
	int		j;
	char	**fdouts;
	char	*str2;

	j = -1;
	fdouts = ft_split_quote(str, ' ');
	while (fdouts[++j])
	{
		str2 = delete_quote(fdouts[j]);
		if (str2[0] == '>' && str2[1] == '>')
			i = open(&str2[2], O_WRONLY | O_CREAT | O_APPEND, 0777);
		else
			i = open(&str2[1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (i < 0)
			return (ft_free_fdout(fdouts), str2);
		free(str2);
		if (i > 1)
			close(i);
	}
	return (ft_free_fdout(fdouts), NULL);
}

int	**check_fd(t_cmds *cmds, t_data *data)
{
	int		**fds;
	int		i;
	t_cmds	*tmp;

	i = 0;
	tmp = cmds;
	fds = malloc(sizeof(int *) * len_cmds_lst(cmds));
	if (!fds)
		return (NULL);
	while (cmds)
	{
		fds[i] = malloc(sizeof(int) * 2);
		if (!fds[i])
			return (free_fds(fds, tmp), NULL);
		fds[i][0] = check_fdin(cmds->in, 0, data);
		fds[i][1] = check_fdout(cmds->out);
		i++;
		cmds = cmds->next;
	}
	return (fds);
}
