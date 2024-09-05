/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:00:49 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/16 00:54:10 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if (((char)c) == 0)
		return (&((char *)s)[i]);
	return (NULL);
}

/*int	main(int argc, char **argv)
{
	char	*k;
	char	*c;

	c = NULL;
	k = NULL;
	if (argc == 2)
	{
		k =ft_strchr(argv[1] ,'t' + 256);
		c =strchr(argv[1] ,'t' + 256);
	}
	if (k != NULL)
		printf("%s\n", k);
	else
		printf("%d\n", k);
	if (c != NULL)
		printf("%s\n", c);
	else
		printf("%d\n", c);
	return (0);
}*/
