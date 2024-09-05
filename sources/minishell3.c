/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:52:47 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/11 14:26:55 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	test_isatty(void)
{
	if (ttyname(0) == NULL)
		exit (0);
	if (ttyname(1) == NULL)
		exit (0);
}

int	check_if_mini(t_cmds *cmds)
{
	if (ft_strncmp(cmds->cmd, "./minishell\0", 12) == 0)
		return (2);
	return (0);
}
