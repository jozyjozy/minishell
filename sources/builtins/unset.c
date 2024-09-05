/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 23:19:34 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/12 13:11:43 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*fill_tmp_unset(char *str)
{
	int		i;
	char	*final;

	final = malloc(sizeof(char) * (ft_strlen(str) + 2));
	i = 0;
	while (str[i])
	{
		final[i] = str[i];
		i++;
	}
	final[i] = '=';
	final[i + 1] = '\0';
	return (final);
}

char	*fill_tmp_unset2(char *str)
{
	int		i;
	char	*final;

	final = malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		final[i] = str[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}

void	remove_var(t_data *data, t_cmds *cmds, int j, int k)
{
	char	**tabtab;
	int		i;
	char	*tmp;

	j = 0;
	i = 0;
	while (data->ms_env[i])
		i++;
	tabtab = malloc(sizeof(char *) * i);
	i = 0;
	tmp = fill_tmp_unset(cmds->opt[k]);
	while (data->ms_env[i])
	{
		if (ft_strncmp(data->ms_env[i], tmp, ft_strlen(tmp)) == 0)
			free(data->ms_env[i++]);
		else
		{
			tabtab[j++] = ft_strdup(data->ms_env[i]);
			free(data->ms_env[i++]);
		}
	}
	tabtab[j] = NULL;
	free(data->ms_env);
	free(tmp);
	data->ms_env = tabtab;
}

void	check_alt(t_data *data, t_cmds *cmds, int j, int k)
{
	char	**tabtab;
	int		i;
	char	*tmp;

	j = 0;
	i = 0;
	while (data->ms_env[i])
		i++;
	tabtab = malloc(sizeof(char *) * (i + 1));
	i = 0;
	tmp = fill_tmp_unset2(cmds->opt[k]);
	while (data->ms_env[i])
	{
		if (ft_strncmp(data->ms_env[i], tmp, ft_strlen(tmp) + 1) == 0)
			free(data->ms_env[i++]);
		else
		{
			tabtab[j++] = ft_strdup(data->ms_env[i]);
			free(data->ms_env[i++]);
		}
	}
	tabtab[j] = NULL;
	free(data->ms_env);
	free(tmp);
	data->ms_env = tabtab;
}

void	ft_unset(t_data *data, t_cmds *cmds)
{
	int		i;
	int		j;
	char	*tmp;

	j = 1;
	if (!(cmds->opt[1]))
	{
		g_signal.exit_status = 0;
		return ;
	}
	while (cmds->opt[j])
	{
		if (cmds->opt[j][0] == '\0')
			j++;
		i = -1;
		tmp = fill_tmp_unset(cmds->opt[j]);
		while (data->ms_env[++i])
			if (ft_strncmp(data->ms_env[i], tmp
					, ft_strlen(tmp)) == 0)
				break ;
		check_unset_ph2(cmds, data, i, j);
		check_alt(data, cmds, i, j);
		j++;
	}
	free(tmp);
}
