/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:22:36 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/15 23:09:28 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_filltab(unsigned int nb, int l, int s)
{
	char	*number;

	number = ft_calloc(sizeof(char), l + 1);
	if (!number)
		return (NULL);
	if (s < 0)
		number[0] = '-';
	while (nb)
	{
		number[--l] = nb % 10 + '0';
		nb = nb / 10 ;
	}
	return (number);
}

char	*ft_itoa(int n)
{
	int long	nb;
	int			s;
	int			l;

	s = 1;
	l = 1;
	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		s = -s;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb /= 10;
		l++;
	}
	return (ft_filltab(n * s, l + (s < 0), s));
}

/*void	main(void)
{
	printf("%s", ft_itoa(-123456789));
}*/
