/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:32:00 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/08 18:04:35 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_quote(char *str)
{
	int	i;
	int	smpl;
	int	dbl;

	i = 0;
	dbl = 1;
	smpl = 1;
	while (str[i])
	{
		if (str[i] == 39 && dbl == 1)
			smpl = -smpl;
		if (str[i] == 34 && smpl == 1)
			dbl = -dbl;
		i++;
	}
	if (smpl != 1 | dbl != 1)
		return (write(2, "Error quote\n", 13));
	return (0);
}

char	*fill_delete_quote(char *final, char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '\'' && str[i++])
		{
			while (str[i] && str[i] != '\'')
				final[j++] = str[i++];
		}
		else if (str[i] == '\"' && str[i++])
		{
			while (str[i] && str[i] != '\"')
				final[j++] = str[i++];
		}
		else
			final[j++] = str[i];
	}
	final[j] = '\0';
	if (j != 0)
		return (final);
	return (free(final), ft_strdup(""));
}

char	*delete_quote(char *str)
{
	int		i;
	int		j;
	char	*final;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '\'' && str[i++])
		{
			while (str[i] && str[i] != '\'')
				i++;
			j += 2;
		}
		else if (str[i] == '\"' && str[i++])
		{
			while (str[i] && str[i] != '\"')
				i++;
			j += 2;
		}
	}
	final = malloc(sizeof(char) * (i - j) + 1);
	if (!final)
		return (NULL);
	return (fill_delete_quote(final, str));
}
