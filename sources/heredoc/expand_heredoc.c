/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:27:41 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/05 14:53:50 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_len_tmp_heredoc(char *line)
{
	int	i;

	i = 1;
	while (line[i] != ' ' && line[i] != '\"' && line[i] != '\'' && line[i])
		i++;
	return (i);
}

int	get_var_2_heredoc(char *line, t_data *data, char *final)
{
	int		i;
	int		k;
	int		x;
	char	*tmp;

	x = 0;
	tmp = malloc(sizeof(char) * (get_len_tmp_heredoc(line) + 2));
	if (!tmp)
		return (0);
	i = fill_tmp_get_var_heredoc(line, tmp, get_len_tmp_heredoc(line));
	while (data->ms_env[i])
	{
		if (ft_strncmp(tmp, data->ms_env[i], get_len_tmp_heredoc(line)) == 0)
		{
			k = get_len_tmp_heredoc(line);
			while (data->ms_env[i][k])
				final[x++] = data->ms_env[i][k++];
			break ;
		}
		i++;
	}
	if (x != 0)
		return (free(tmp), (int)ft_strlen(data->ms_env[i])
			- get_len_tmp_heredoc(line));
	return (free(tmp), not_found_heredoc(final, line));
}

char	*fill_exp_heredoc(char *line, t_data *data, int len, int i)
{
	char	*final;
	int		j;

	j = 0;
	final = malloc(sizeof(char) * (len + 2));
	if (!final)
		return (NULL);
	while (line[i])
	{
		if (line[i] == '$')
		{
			j += get_var_2_heredoc(&line[i], data, &final[j]);
			i++;
			i += pass_exp_heredoc(&line[i]);
		}
		else
			final[j++] = line[i++];
	}
	final[j] = '\0';
	return (final);
}

int	get_var_heredoc(char *line, t_data *data)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (line[i] != ' ' && line[i] != '\"' && line[i] != '$'
		&& line[i] != '=' && line[i])
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

char	*ft_expand_heredoc(char *line, t_data *data, int i)
{
	int	j;

	j = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			j += (get_var_heredoc(&line[i], data));
			i++;
			i += pass_exp_heredoc(&line[i]);
		}
		else
		{
			j++;
			i++;
		}
	}
	return (fill_exp_heredoc(line, data, j, 0));
}
