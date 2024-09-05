/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:03:49 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/16 00:49:19 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d\n", ft_tolower(argv[1][0]));
		printf("%d\n", tolower(argv[1][1]));
	}
	return (0);
}*/
