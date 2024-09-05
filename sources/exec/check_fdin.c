/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:27:16 by jlarue            #+#    #+#             */
/*   Updated: 2023/05/12 10:24:39 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_fdin(char **fdins)
{
	int	i;

	i = 0;
	while (fdins[i])
	{
		free(fdins[i]);
		i++;
	}
	free(fdins);
}

int	isquote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

int	do_open(t_data *data, char *str2, int k, int qot)
{
	int	i;

	i = 0;
	if (str2[0] == '<' && str2[1] != '<')
		i = open(&str2[1], O_RDONLY);
	else if (k == 0)
		i = ft_heredoc(&str2[2], data, qot);
	return (i);
}

int	check_fdin(char *str, int k, t_data *data)
{
	int		i;
	int		j;
	int		qot;
	char	*str2;
	char	**fdins;

	j = -1;
	fdins = ft_split_quote(str, ' ');
	while (fdins[++j])
	{
		if (g_signal.exit_status == SCRIPT_ENDED_CTRL_C)
			break ;
		qot = isquote(fdins[j]);
		str2 = delete_quote(fdins[j]);
		i = 0;
		i = do_open(data, str2, k, qot);
		free(str2);
		if (i == -1)
			return (ft_free_fdin(fdins), -1);
		if (!fdins[j + 1])
			return (ft_free_fdin(fdins), i);
		((i > 0) && close(i));
	}
	return (ft_free_fdin(fdins), 0);
}
