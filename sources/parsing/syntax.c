/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:57:43 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/08 12:53:20 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_if_word_before(char *line)
{
	int	i;
	int	j;

	j = 0;
	while (line[j] == ' ')
		j++;
	i = j;
	while ((line[i] != ' ' && line[i] != '|') && line[i])
		i++;
	if (i - j == 0)
		return (0);
	return (1);
}

int	check_pipe(char *line, int slp, int dbl)
{
	int	i;

	i = -1;
	if (check_if_word_before(line) == 0)
		return (1);
	while (line[++i])
	{
		((line[i] == '\'' && dbl == 1) && (slp = -slp));
		((line[i] == '\"' && slp == 1) && (dbl = -dbl));
		if (line[i] == '|' && dbl == 1 && slp == 1)
		{
			if (!line[i + 1])
				return (1);
			i++;
			while (line[i])
			{
				if (line[i] == '|')
					return (1);
				if (line[i] != ' ')
					break ;
				i++;
			}
		}
	}
	return (0);
}

int	ft_check_bracket_in(char *line)
{
	int	i;
	int	chk;
	int	spc;

	spc = 0;
	i = -1;
	chk = 0;
	while (line[++i])
	{
		if (line[i] == '<' && spc != 0)
			return (1);
		if (line[i] == '<')
			chk++;
		if (chk > 2)
			return (1);
		if (line[i] == '>')
			return (1);
		if (line[i] == '|')
			return (1);
		if (line[i] == ' ')
			spc++;
		if (line[i] != ' ' && line[i] != '<')
			return (0);
	}
	return (1);
}

int	ft_check_bracket_out(char *line)
{
	int	i;
	int	chk;
	int	spc;

	i = -1;
	chk = 0;
	spc = 0;
	while (line[++i])
	{
		if (line[i] == '>' && spc != 0)
			return (1);
		if (line[i] == '>')
			chk++;
		if (chk > 2)
			return (1);
		if (line[i] == '<')
			return (1);
		if (line[i] == '|')
			return (1);
		if (line[i] == ' ')
			spc++;
		if (line[i] != ' ' && line[i] != '>')
			return (0);
	}
	return (1);
}

int	check_angle_brackets(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '<')
			if (ft_check_bracket_in(&line[i]) == 1)
				return (1);
		if (line[i] == '>')
			if (ft_check_bracket_out(&line[i]) == 1)
				return (1);
		i++;
	}
	return (0);
}
