/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:10:24 by agiguair          #+#    #+#             */
/*   Updated: 2023/01/31 13:33:00 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s == NULL)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (s[i])
		i++;
	count = write(1, s, i);
	return (count);
}

int	ft_putnbr(int n)
{
	char	*num;
	int		count;

	count = 0;
	num = ft_itoa(n);
	count = ft_putstr(num);
	free(num);
	return (count);
}

int	ft_putuns(unsigned int n)
{
	char	*num;
	int		count;

	count = 0;
	num = ft_itoauns(n);
	count += ft_putstr(num);
	free(num);
	return (count);
}
