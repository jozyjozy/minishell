/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:14:27 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/23 19:14:17 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choix(va_list arg, char s)
{
	ssize_t	count;

	count = 0;
	if (s == 'x')
		count += ft_hexa(va_arg(arg, int), 'x');
	if (s == 'X')
		count += ft_hexa(va_arg(arg, int), 'X');
	if (s == 'i')
		count += ft_putnbr(va_arg(arg, int));
	if (s == 'd')
		count += ft_putnbr(va_arg(arg, int));
	if (s == 'c')
		count += ft_putchar(va_arg(arg, int));
	if (s == 's')
		count += ft_putstr(va_arg(arg, char *));
	if (s == 'u')
		count += ft_putuns(va_arg(arg, unsigned int));
	if (s == 'p')
		count += ft_adrpoint((unsigned long int)va_arg(arg, void *));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	ssize_t	count;

	i = -1;
	count = 0;
	va_start(arg, str);
	while (str[++i])
	{
		if (count == -1)
			return (count);
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				count += write(1, "%", 1);
			if (str[i] == 'd' || str[i] == 'i' || str[i] == 'c' || str[i] == 'x'
				|| str[i] == 'X' || str[i] == 's' || str[i] == 'u'
				|| str[i] == 'p')
				count += ft_choix(arg, str[i]);
		}
		else
			count += ft_putchar(str[i]);
	}
	return (va_end(arg), count);
}
