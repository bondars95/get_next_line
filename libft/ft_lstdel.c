/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:02:10 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/02 13:34:01 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *current;

	current = *alst;
	next = current->next;
	del(current->content, current->content_size);
	current = next;
	if (alst != NULL)
	{
		while (current != NULL)
		{
			next = current->next;
			del(current->content, current->content_size);
			free(current);
			current = next;
		}
		free(*alst);
		*alst = NULL;
	}
}
