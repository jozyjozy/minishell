/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 06:54:57 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/12 10:27:15 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_export_join(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	if (str[i - 1] && str[i - 1] == '+')
		return (1);
	return (0);
}

void	export_add_var(char *str, t_data *data, int k)
{
	int		i;
	char	**tab;
	char	*tmp;

	i = 0;
	tab = malloc(sizeof(char *) * (k + 2));
	if (!tab)
		return ;
	while (data->ms_env[i])
	{
		tab[i] = ft_strdup(data->ms_env[i]);
		free(data->ms_env[i]);
		i++;
	}
	free(data->ms_env);
	tmp = fill_tmp_export_all(str);
	tab[i] = ft_strdup(tmp);
	free(tmp);
	tab[i + 1] = NULL;
	data->ms_env = tab;
	return ;
}

char	*fill_tmp_export(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i])
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '=')
		{
			if (str[i] == '+')
				tmp[i] = str[i + 1];
			else
				tmp[i] = str[i];
			break ;
		}
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	gg(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	i++;
	return (i);
}

void	do_export(char *str, t_data *data)
{
	int		i;
	char	*str2;
	char	*tmp;

	i = 0;
	tmp = fill_tmp_export(str);
	if (!tmp)
		return ;
	while (data->ms_env[i])
	{
		if (ft_strncmp(data->ms_env[i], tmp, ft_strlen(tmp)) == 0)
		{
			str2 = data->ms_env[i];
			if (check_export_join(str) == 1)
				data->ms_env[i] = ft_strjoin(data->ms_env[i], &str[gg(str)]);
			else
				data->ms_env[i] = ft_strdup(str);
			free(str2);
			free(tmp);
			return ;
		}
		i++;
	}
	free(tmp);
	export_add_var(str, data, i);
}
