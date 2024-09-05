/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 00:44:38 by agiguair          #+#    #+#             */
/*   Updated: 2023/04/28 02:27:08 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_quote(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\'')
	{
		i++;
		while (str[i] && str[i] != '\'')
			i++;
		i++;
	}
	else if (str[i] == '\"')
	{
		i++;
		while (str[i] && str[i] != '\"')
			i++;
		i++;
	}
	return (i);
}

static int	count_words(const char *str, char charset)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == charset))
			i++;
		while (str[i] && (str[i] == charset))
			i++;
		if (str[i] && !(str[i] == charset))
		{
			cpt++;
			while (str[i] && str[i] != charset)
			{
				if (ft_quote(&str[i]))
					i += ft_quote(&str[i]);
				else
					i++;
			}
		}
	}
	return (cpt);
}

static int	len_words(const char *str, char charset)
{
	int	k;

	k = 0;
	while (str[k])
	{
		if (str[k] == charset || !str[k])
			break ;
		if (ft_quote(&str[k]))
			k += ft_quote(&str[k]);
		else
			k++;
	}
	return (k);
}

static void	fill_words(char **split, const char *str, char charset, int words)
{
	int	j;
	int	k;
	int	i;

	i = 0;
	j = 0;
	k = 0;
	while (i < words)
	{
		while (str[j] && charset == str[j])
			j++;
		k = 0;
		k += len_words(&str[j], charset);
		split[i] = ft_calloc((k + 1), sizeof(char));
		if (!split[i])
		{
			free_tab_split(split, i);
		}
		if (split[i] != 0)
			ft_strncpy(split[i], &str[j], k);
		j += k;
		i++;
	}
	split[i] = 0;
}

char	**ft_split_quote(const char *str, char charset)
{
	char	**split;
	int		words;

	if (str == NULL)
		return (NULL);
	words = (count_words(str, charset));
	split = ft_calloc((words + 1), sizeof(char *));
	if (!split)
		return (NULL);
	fill_words(split, str, charset, words);
	return (split);
}
