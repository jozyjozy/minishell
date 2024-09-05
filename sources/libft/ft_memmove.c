/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:23:49 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/16 21:28:03 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;

	i = 0;
	if (!dest && !src)
		return (NULL);
	destination = (unsigned char *) dest;
	source = (unsigned char *) src;
	if (destination > source)
		while (n-- > 0)
			destination[n] = source[n];
	else
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (destination);
}
