/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:09:19 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/12 10:38:10 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(t_data *data, t_cmds *cmds)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(data->ms_env) || cmds->opt[1])
	{
		g_signal.exit_status = BAD_USE_BUILTINS;
		return ;
	}
	while (data->ms_env[i])
	{
		if (ft_strrchr(data->ms_env[i], '='))
			j = printf("%s\n", data->ms_env[i]);
		if (j == -1)
		{
			g_signal.exit_status = GENERAL_ERROR;
			write(2, "Minishell: env: write error: \
No space left on device\n", 54);
			return ;
		}
		i++;
	}
	g_signal.exit_status = 0;
}
