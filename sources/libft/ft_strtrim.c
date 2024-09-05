/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:33:37 by agiguair          #+#    #+#             */
/*   Updated: 2022/11/16 04:20:51 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	s;
	int	e;
	int	i;

	if (!s1 || !set)
		return (NULL);
	i = ft_strlen(s1);
	s = 0;
	e = i - 1;
	while (s < i && ft_strchr(set, s1[s]))
		s++;
	while (e > 0 && e > s && ft_strchr(set, s1[e]))
		e--;
	return (ft_substr(s1, s, e - s + 1));
}
