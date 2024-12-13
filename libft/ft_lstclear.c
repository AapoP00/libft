/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:22:48 by apuisto           #+#    #+#             */
/*   Updated: 2024/11/13 12:22:51 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;
	t_list	*next;

	if (lst)
	{
		p = *lst;
		while (p)
		{
			next = p->next;
			ft_lstdelone(p, (del));
			p = next;
		}
	}
	*lst = NULL;
}
