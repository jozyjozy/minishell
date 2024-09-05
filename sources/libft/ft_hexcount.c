/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:12:42 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/23 12:13:04 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexcount(long long unsigned int i)
{
	int	count;

	count = 0;
	while (i != 0)
	{
		count++;
		i = i / 16;
	}
	return (count);
}
