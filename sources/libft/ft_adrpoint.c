/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adrpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:15:23 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/23 12:15:42 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_adrpoint(long long unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		count += write(1, "(nil)", 5);
	if (nbr != 0)
	{
		count += write(1, "0x", 2);
		ft_adrpoint2(nbr);
		return (ft_hexcount(nbr) + count);
	}
	return (5);
}

int	ft_adrpoint2(long long unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		ft_adrpoint2(nbr / 16);
		ft_adrpoint2(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			count += ft_putchar(nbr + '0');
		else
			count += ft_putchar(nbr - 10 + 'a');
		if (count == -1)
			return (-1);
	}
	return (0);
}
