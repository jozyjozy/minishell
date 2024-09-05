/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 07:53:25 by agiguair          #+#    #+#             */
/*   Updated: 2023/05/05 09:09:59 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*fill_tmp_export_all(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[j])
	{
		if (str[j] == '+' && str[j + 1] && str[j + 1] == '=')
		{
			j++;
		}
		tmp[i] = str[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}
