/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fdout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:13:37 by jlarue            #+#    #+#             */
/*   Updated: 2023/05/22 15:16:22 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_fdout(char **fdouts)
{
	int	i;

	i = 0;
	while (fdouts[i])
	{
		free(fdouts[i]);
		i++;
	}
	free(fdouts);
}

int	check_fdout(char *str)
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
			i = open(&str2[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		free(str2);
		if (!fdouts[j + 1])
			return (ft_free_fdout(fdouts), i);
		if (i < 0)
			return (i);
		close(i);
	}
	return (ft_free_fdout(fdouts), 1);
}

void	perrorms(t_cmds *cmds)
{
	char	*str;

	str = get_name_error(cmds->in);
	perror(str);
	free(str);
}

void	perrorms2(t_cmds *cmds)
{
	char	*str;

	str = get_name_error2(cmds->out);
	if (str[0] == '>' && str[1] == '>')
		perror(&str[2]);
	else
		perror(&str[1]);
	free(str);
}
