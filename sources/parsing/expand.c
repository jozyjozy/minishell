/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:39:35 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/09 12:10:01 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_len_tmp(char *line)
{
	int	i;

	i = 1;
	while (line[i] != ' ' && line[i] != '\"' && line[i] != '\''
		&& line[i] != '$' && line[i] != '=' && line[i])
		i++;
	return (i);
}

int	get_var_2(char *line, t_data *data, char *final, int dbl)
{
	int		i;
	int		k;
	int		x;
	char	*tmp;

	x = 0;
	tmp = malloc(sizeof(char) * get_len_tmp(line) + 2);
	if (!tmp)
		return (0);
	i = fill_tmp_get_var(line, tmp, get_len_tmp(line));
	while (data->ms_env[i])
	{
		if (ft_strncmp(tmp, data->ms_env[i], get_len_tmp(line)) == 0)
		{
			k = get_len_tmp(line);
			while (data->ms_env[i][k])
				final[x++] = data->ms_env[i][k++];
			break ;
		}
		i++;
	}
	if (x != 0)
		return (free(tmp), (int)ft_strlen(data->ms_env[i]) - get_len_tmp(line));
	return (free(tmp), not_found(final, line, dbl));
}

char	*fill_exp(char *line, t_data *data, long long len, int i)
{
	char	*final;
	int		j;
	int		slp;
	int		dbl;

	j = 0;
	slp = 1;
	dbl = 1;
	final = malloc(sizeof(char) * (len + 3));
	if (!final)
		return (NULL);
	while (line[i])
	{
		((line[i] == '\'' && dbl == 1) && (slp = -slp));
		((line[i] == '\"' && slp == 1) && (dbl = -dbl));
		if (line[i] == '$' && slp != -1 && not_here_doc(line, i) == 1)
		{
			j += get_var_2(&line[i++], data, &final[j], dbl);
			i += pass_exp(&line[i]);
		}
		else
			final[j++] = line[i++];
	}
	final[j] = '\0';
	return (final);
}

int	get_var(char *line, t_data *data)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (line[i] != ' ' && line[i] != '\"' && line[i] != '='
		&& line[i] != '$' && line[i] != '\'' && line[i])
		i++;
	j = i;
	tmp = malloc(sizeof(char) * i + 2);
	if (!tmp)
		return (0);
	i = 0;
	while (++i != j)
		tmp[i - 1] = line[i];
	tmp[i - 1] = '=';
	tmp[i] = '\0';
	i = -1;
	while (data->ms_env[++i])
		if (ft_strncmp(tmp, data->ms_env[i], j) == 0)
			break ;
	free(tmp);
	if (data->ms_env[i])
		return ((int)ft_strlen(data->ms_env[i]) - j);
	return (j);
}

char	*ft_expand(char *line, t_data *data, long long i)
{
	int			slp;
	int			dbl;
	long long	j;

	slp = 1;
	dbl = 1;
	j = 0;
	while (line[i])
	{
		((line[i] == '\'' && dbl == 1) && (slp = -slp));
		((line[i] == '\"' && slp == 1) && (dbl = -dbl));
		if (line[i] == '$' && slp != -1 && not_here_doc(line, i) == 1)
		{
			j += (get_var(&line[i], data));
			i++;
			i += pass_exp(&line[i]);
		}
		else
		{
			j++;
			i++;
		}
	}
	return (fill_exp(line, data, j, 0));
}
