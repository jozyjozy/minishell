/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 21:39:36 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/08 18:11:22 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	fill_tmp_get_var(char *line, char *tmp, int j)
{
	int	i;

	i = 0;
	while (++i != j)
		tmp[i - 1] = line[i];
	tmp[i - 1] = '=';
	tmp[i] = '\0';
	return (0);
}

int	fontion_return(char *final)
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

int	not_found(char *final, char *line, int dbl)
{
	int	i;

	i = 1;
	while (line[i] != ' ' && line[i] != '\"' && line[i] && line[i] != '$')
		i++;
	if (i == 1)
	{
		final[0] = line[0];
		return (1);
	}
	if (i > 1 && line[1] == '?')
		return (fontion_return(final));
	else if (dbl == 1 && i != 1)
	{
		final[0] = '\"';
		final[1] = ' ';
		final[2] = '\"';
		return (3);
	}
	else if (dbl == -1 && i != 1)
		final[0] = ' ';
	if (line[i] == '\"')
		return (0);
	return (1);
}

int	pass_exp(char *line)
{
	int	i;

	i = 0;
	while (line[i] != ' ' && line[i] != '\"' && line[i] != '='
		&& line[i] != '\'' && line[i] && line[i] != '$')
		i++;
	if (i > 1 && line[0] == '?')
		return (1);
	return (i);
}
