/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:21:33 by agiguair          #+#    #+#             */
/*   Updated: 2022/12/06 10:28:03 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <stdlib.h>
# include "libft.h"

int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putnbr(int n);
int				ft_choix(va_list arg, char s);
int				ft_putuns(unsigned int n);
#endif
