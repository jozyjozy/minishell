/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:25:53 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/11 12:41:00 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_longlong(char *str)
{
	long long	i;
	long long	k;
	int			j;

	j = 1;
	k = 223372036854775807;
	if (ft_strlen(str) > 20)
		return (1);
	if (str[0] == '-' || str[0] == '+')
	{
		k++;
		j++;
	}
	i = ft_atoll(&str[j]);
	if (i > k && str[j - 1] == '9')
		return (1);
	return (0);
}

int	check_if_alpha(char *str)
{
	int	i;
	int	chk;

	i = 0;
	chk = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
		{
			if ((str[i] == '-' || str[i] == '+') && chk == 0)
				chk = 0;
			else
				return (1);
		}
		if (str[i] == '-' || str[i] == '+')
			chk++;
		i++;
	}
	if (check_longlong(str) == 1)
		return (1);
	return (0);
}

void	writeerror(t_cmds *cmds)
{
	write (2, "Minishell: exit: ", 17);
	write (2, cmds->opt[1], ft_strlen(cmds->opt[1]));
	write (2, ": numeric argument required\n", 29);
}

void	ft_exit(t_data *data, t_cmds *cmds)
{
	int	i;

	i = g_signal.exit_status;
	if (cmds && cmds->opt[1])
	{
		if (check_if_alpha(cmds->opt[1]) == 0)
			i = ft_atoll(cmds->opt[1]);
		if (check_if_alpha(cmds->opt[1]) == 1)
			i = BAD_USE_BUILTINS;
		if (cmds->opt[1] && cmds->opt[2] && (check_if_alpha(cmds->opt[1]) == 0))
		{
			g_signal.exit_status = 1;
			write(2, "Minishell: exit: too many arguments\n", 37);
			return ;
		}
	}
	write(2, "exit\n", 5);
	if (i == 2)
		writeerror(cmds);
	ft_lstclear_cmd(cmds);
	ft_free_data(data);
	exit ((unsigned char)i);
}
