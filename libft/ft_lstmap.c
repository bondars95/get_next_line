/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:25:59 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/02 13:41:38 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*current;

	new_list = NULL;
	if (lst != NULL)
	{
		if ((new_list = (*f)(lst)) == NULL)
			return (NULL);
		current = new_list;
		while (lst->next != NULL)
		{
			if ((current->next = (*f)(lst->next)) == NULL)
				return (NULL);
			current = current->next;
			lst = lst->next;
		}
	}
	return (new_list);
}
