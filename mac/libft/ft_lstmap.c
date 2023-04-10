/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:05:50 by lle-bret          #+#    #+#             */
/*   Updated: 2022/09/25 20:05:52 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*last;

	new = NULL;
	while (lst)
	{
		last = ft_lstnew((*f)(lst->content));
		if (!last)
		{
			while (new)
			{
				last = new->next;
				ft_lstdelone(new, del);
				new = last;
			}
			return (NULL);
		}
		ft_lstadd_back(&new, last);
		lst = lst->next;
	}
	return (new);
}
