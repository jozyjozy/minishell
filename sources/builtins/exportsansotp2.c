/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportsansotp2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:02:07 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/12 10:37:05 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_export(char *tab)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(tab) + 6));
	i = -1;
	while (tab[++i] != '=' && tab[i])
		str[i] = tab[i];
	str[i] = tab[i];
	str[i + 1] = '\"';
	while (tab[i++])
		str[i + 1] = tab[i];
	str[i + 1] = '\0';
	j = printf("declare -x %s", str);
	if (ft_strrchr(tab, '='))
		j = printf("\"\n");
	else
		j = printf("\n");
	free(str);
	if (j == -1)
	{
		g_signal.exit_status = GENERAL_ERROR;
		write(2, "Minishell: export: write error: \
No space left on device\n", 59);
	}
}
