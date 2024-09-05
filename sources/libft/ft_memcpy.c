/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:19:04 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/16 21:27:25 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destination;
	unsigned char	*source;

	i = 0;
	if (!dest && !src)
		return (NULL);
	destination = (unsigned char *) dest;
	source = (unsigned char *) src;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
