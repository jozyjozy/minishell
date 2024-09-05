/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:13:28 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/23 12:13:40 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa(unsigned int nbr, char format)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (nbr == 0)
		count += write(1, "0", 1);
	if (nbr != 0)
	{
		i += ft_hex(nbr, format);
		if (i < 0)
			return (-1);
		count += ft_hexcount(nbr);
	}
	return (count);
}
