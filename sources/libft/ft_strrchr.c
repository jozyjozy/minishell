/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 03:46:41 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/16 00:55:39 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
		if (s[i--] == ((char)c))
			return ((char *)&s[++i]);
	return (NULL);
}

/*int	main(int argc, char **argv)
{
	char	*k;
	char	*c;

	c = NULL;
	k = NULL;
	if (argc == 3)
	{
		k =ft_strrchr(argv[1] ,argv[2][0]);
		c =strrchr(argv[1] ,argv[2][0]);
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
