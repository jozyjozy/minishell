/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:40:52 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/08 18:11:10 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	export_opt(char *str)
{
	write(2, "Minishell: export:-", 20);
	write(2, &str[1], 1);
	write(2, ": invalid option\n", 18);
	if (g_signal.exit_status == 0)
		g_signal.exit_status = BAD_USE_BUILTINS;
}

void	not_valid_identifier(char *str)
{
	if (g_signal.checker == 0)
	{
		write(2, "Minishell: export:`", 20);
		write(2, str, ft_strlen(str));
		write(2, "': not a valid identifier\n", 27);
	}
	if (g_signal.exit_status == 0)
		g_signal.exit_status = 1;
}

int	event_not_found(char *str, int bol)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '!' && bol == 1)
			return (1);
		if (str[i] == '!' && bol == 0)
			break ;
		i++;
	}
	if (bol == 0)
	{
		write(2, "Minishell: ", 12);
		write(2, &str[i], ft_strlen(&str[i]));
		write(2, ": event not found\n", 19);
	}
	return (0);
}

int	check_export(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1])
		return (export_opt(str), 1);
	if (ft_isdigit(str[i]) == 1 || str[i] == '=')
		return (not_valid_identifier(str), 1);
	while (str[i] && str[i] != '=' && str[i] != '+')
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			return (not_valid_identifier(str), 1);
		i++;
	}
	if (event_not_found(str, 1) == 1)
	{
		event_not_found(str, 0);
		return (1);
	}
	return (0);
}

void	ft_export(t_cmds *cmds, t_data *data)
{
	int	i;

	i = 1;
	g_signal.exit_status = 0;
	if (!cmds->opt[1] || (cmds->opt[1][0]
		== ' ' && cmds->opt[1][1] == '\0' && !cmds->opt[2]))
		return (export_ascii(data));
	while (cmds->opt[i])
	{
		if (check_export(cmds->opt[i]) == 0)
			if (cmds->opt[i][0] != '\0')
				do_export(cmds->opt[i], data);
		i++;
	}
}
