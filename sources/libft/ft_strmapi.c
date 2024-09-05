/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 04:24:47 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/16 04:34:38 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				len;
	char			*str;

	i = 0;
	len = ft_strlen(s);
	str = ft_calloc(len + 1, (sizeof (char)));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, ((char *)s)[i]);
		i++;
	}
	return (str);
}
