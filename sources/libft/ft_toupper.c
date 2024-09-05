/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:25:16 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/16 00:49:27 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%d\n", ft_toupper(argv[1][0]));
		printf("%d\n", toupper(argv[1][1]));
	}
	return (0);
}*/
