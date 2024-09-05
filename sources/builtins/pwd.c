/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:12:21 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/11 10:49:42 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	printf_pwd(char *str2)
{
	int	i;

	i = printf("%s\n", str2);
	if (i == -1)
	{
		write(2, "Minishell: pwd: write error: \
No space left on device\n", 56);
		g_signal.exit_status = GENERAL_ERROR;
	}
}

void	ft_pwd(t_cmds *cmds)
{
	char	*str;
	char	*str2;
	int		i;

	str = NULL;
	i = -1;
	while (cmds->opt[++i])
	{
		if (cmds->opt[i][0] == '-')
		{
			write(2, "Minishell : pwd:", 17);
			write(2, cmds->opt[i], ft_strlen(cmds->opt[i]));
			write(2, ": invalid option\n", 18);
			return ;
		}
	}
	str2 = getcwd(str, 0);
	if (!str2)
		write(2, "pwd: error retrieving current directory: getcwd:\
cannot access parent directories: No such file or directory\n", 109);
	else
		printf_pwd(str2);
	if (str)
		free(str);
	if (str2)
		free(str2);
}
