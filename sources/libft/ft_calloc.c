/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:21:04 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/16 02:31:57 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*str;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	str = malloc(size * nmemb);
	if (!str)
		return (NULL);
	ft_bzero(str, (nmemb * size));
	return (str);
}
