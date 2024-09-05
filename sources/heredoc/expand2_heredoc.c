/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:29:49 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/03 08:48:58 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	fill_tmp_get_var_heredoc(char *line, char *tmp, int j)
{
	int	i;

	i = 0;
	while (++i != j)
		tmp[i - 1] = line[i];
	tmp[i - 1] = '=';
	tmp[i] = '\0';
	return (0);
}

int	fontion_return_heredoc(char *final)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa((int)g_signal.exit_status);
	while (str[i])
	{
		final[i] = str[i];
		i++;
	}
	free(str);
	return (i);
}

int	not_found_heredoc(char *final, char *line)
{
	int	i;

	i = 1;
	while (line[i] != ' ' && line[i] != '\"' && line[i] && line[i] != '$')
	{
		i++;
	}
	if (i == 1)
		final[0] = line[0];
	if (i == 2 && line[1] == '?')
		return (fontion_return_heredoc(final));
	return (0);
}

int	pass_exp_heredoc(char *line)
{
	int	i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\"'
		&& line[i] != '\'' && line[i] && line[i] != '$')
		i++;
	return (i);
}
