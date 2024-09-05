/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 23:15:25 by jlarue            #+#    #+#             */
/*   Updated: 2023/05/08 18:10:51 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_unset_ph(t_cmds *cmds, int j)
{
	int	i;

	i = 0;
	if (cmds->opt[j][0] == '-')
		return (2);
	while (cmds->opt[j][i])
	{
		if (cmds->opt[j][i] == '!')
		{
			write(2, "Minishell: '", 13);
			write(2, &cmds->opt[j][i], ft_strlen(&cmds->opt[j][i]));
			write(2, "': event not found\n", 20);
			return (4);
		}
		if (cmds->opt[j][i] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	check_unset_ph2(t_cmds *cmds, t_data *data, int i, int j)
{
	if (data->ms_env[i] && check_unset_ph(cmds, j) == 1)
		remove_var(data, cmds, i, j);
	else if (check_unset_ph(cmds, j) == 4)
		g_signal.exit_status = 1;
	else if (check_unset_ph(cmds, j) == 2)
	{
		if (cmds->opt[j][i])
			printf("Minishell: unset: %c%c: \
invalid option\n", cmds->opt[j][0], cmds->opt[j][1]);
		else
			printf("Minishell: unset: %c: \
invalid option\n", cmds->opt[j][0]);
		g_signal.exit_status = 2;
	}
	else
			g_signal.exit_status = 0;
}
