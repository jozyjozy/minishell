/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:01:53 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/11 12:48:59 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_shlvl(char *shlvl)
{
	int		nb;
	char	*str;
	char	*str2;

	nb = ft_atoi(&shlvl[6]);
	str = ft_itoa(nb + 1);
	str2 = ft_strjoin("SHLVL=", str);
	free(str);
	return (str2);
}

void	do_old_pwd(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (data->ms_env[i])
	{
		if (ft_strncmp(data->ms_env[i], "OLDPWD=", 7) == 0)
		{
			free(data->ms_env[i]);
			data->ms_env[i] = ft_strjoin("OLDPWD", &str[3]);
		}
		i++;
	}
}

char	*refresh_pwd(char *str, t_data *data)
{
	char	*new;
	char	*str2;

	str2 = NULL;
	new = getcwd(str2, 0);
	if (str2)
		free(str2);
	if (ft_strncmp(&str[4], new, (ft_strlen(new) + 1)) == 0)
		return (free(new), str);
	do_old_pwd(str, data);
	free(str);
	str = ft_strjoin("PWD=", new);
	free(new);
	return (str);
}

void	do_pwd(t_data *data)
{
	int		i;

	i = 0;
	while (data->ms_env[i])
	{
		if (ft_strncmp(data->ms_env[i], "PWD=", 4) == 0)
		{
			data->ms_env[i] = refresh_pwd(data->ms_env[i], data);
			return ;
		}
		i++;
	}
}

t_data	*do_env(char **env, t_data *data, char *str)
{
	int		i;

	i = -1;
	if (env[0] != NULL)
	{
		data->ms_env = malloc(sizeof(char *) * (ft_nbl(env) + 1));
		if (!data->ms_env)
			sus(data, GENERAL_ERROR);
		while (env[++i])
		{
			if (ft_strncmp(env[i], "SHLVL=", 6) == 0)
				data->ms_env[i] = ft_shlvl(env[i]);
			else
				data->ms_env[i] = ft_strdup(env[i]);
		}
		data->ms_env[i] = NULL;
		return (data);
	}
	data->ms_env = malloc(sizeof(char *) * 3);
	if (!data->ms_env)
		sus(data, GENERAL_ERROR);
	data->ms_env[0] = ft_strjoin("PWD=", getcwd(str, 0));
	data->ms_env[1] = ft_strjoin("SHLVL=", "1");
	data->ms_env[2] = NULL;
	return (data);
}
