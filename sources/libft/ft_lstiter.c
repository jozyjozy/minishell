/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiguair <agiguair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:31:35 by agiguair          #+#    #+#             */
/*   Updated: 2023/03/24 12:31:41 by agiguair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tampon;

	if (!lst)
		return ;
	else
	{
		while (lst)
		{
			tampon = lst->next;
			f(lst->content);
			lst = tampon;
		}
	}
	return ;
}
