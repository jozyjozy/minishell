/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:50:33 by agiguair          #+#    #+#             */
/*   Updated: 2023/04/13 03:09:40 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_tab_split(char **tab, int fill_size)
{
	int	i;

	i = 0;
	while (i < fill_size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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
		if (str[i] && !(str[i] == charset))
		{
			cpt++;
			while (str[i] && !(str[i] == charset))
				i++;
		}
	}
	return (cpt);
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
		while (str[j + k] && !(str[j + k] == charset))
			k++;
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

char	**ft_split(const char *str, char charset)
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

/*void	main(void)
{
	int	i;
	int	j;
	char	*m = "je suis un petit suicide des famille";
	char	*n = " ";

	i = 0;
	j = 0;
	while (ft_split(m, n)[i])
	{
		j = 0;
		while (ft_split(m, n)[i][j])
		{
			printf("%c", ft_split(m, n)[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}*/
