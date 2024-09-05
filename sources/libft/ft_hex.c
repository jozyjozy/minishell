/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:14:28 by agiguair          #+#    #+#             */
/*   Updated: 2022/12/06 10:27:03 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	int	nb;

	nb = write(1, &c, 1);
	return (nb);
}

int	ft_hex(unsigned int nbr, char format)
{
	int	test;

	test = 0;
	if (nbr >= 16)
	{
		test += ft_hex(nbr / 16, format);
		test += ft_hex(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
		{
			test += ft_putchar(nbr + '0');
			if (test < 0)
				return (test);
		}
		else
		{
			((format == 'x') && (test += ft_putchar(nbr - 10 + 'a')));
			((format == 'X') && (test += ft_putchar(nbr - 10 + 'A')));
		}
	}
	return (test);
}
