/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*				                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:22:36 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/23 13:59:16 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoauns(unsigned int n)
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
