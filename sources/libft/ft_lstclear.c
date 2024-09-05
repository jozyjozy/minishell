/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:32:34 by agiguair          #+#    #+#             */
/*   Updated: 2023/03/24 12:32:41 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void	*))
{
	t_list	*tampon;

	if (!lst)
		return ;
	else
	{
		while (*lst)
		{
			tampon = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = tampon;
		}
	}
	return ;
}
