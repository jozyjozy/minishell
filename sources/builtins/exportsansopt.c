/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportsansopt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:10:41 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/11 10:44:21 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strncmp2(const char *s1, const char s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2) && i < n)
	{
		if (s1[i] != s2)
			return ((unsigned char)s1[i] - (unsigned char)s2);
		i++;
	}
	return (0);
}

int	ft_get_not_in_tab(char *str, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_strncmp(str, tab[i], ft_strlen(str)) == 0)
			break ;
		i++;
	}
	if (!tab[i])
		return (1);
	return (0);
}

char	**get_low(t_data *data, char **tab, int j)
{
	int	chk;
	int	k;

	chk = 1;
	while (chk != 0)
	{
		chk = 0;
		k = 0;
		while (data->ms_env[k])
		{
			if (ft_strncmp(data->ms_env[k], tab[j],
					ft_strlen(data->ms_env[k])) < 0)
			{
				if (ft_get_not_in_tab(data->ms_env[k], tab) == 1)
				{
					chk++;
					tab[j] = data->ms_env[k];
				}
			}
			k++;
		}
	}
	return (tab);
}

char	**get_str_ea(char **tab, t_data *data, int j)
{
	int	k;

	k = 0;
	while (data->ms_env[k])
	{
		if (ft_get_not_in_tab(data->ms_env[k], tab) == 1)
		{
			tab[j] = data->ms_env[k];
			break ;
		}
		k++;
	}
	return (tab);
}

void	export_ascii(t_data *data)
{
	int		i;
	char	**tab;
	int		k;
	int		j;

	i = 0;
	while (data->ms_env[i])
		i++;
	tab = malloc(sizeof(char *) * (i + 1));
	j = -1;
	tab[j + 1] = NULL;
	while (i > ++j)
	{
		tab[j + 1] = NULL;
		k = -1;
		tab = get_str_ea(tab, data, j);
		tab = get_low(data, tab, j);
	}
	j = -1;
	while (tab[++j] && g_signal.exit_status != GENERAL_ERROR)
	{
		if (g_signal.checker != 0)
			print_export(tab[j]);
	}
	free(tab);
}
