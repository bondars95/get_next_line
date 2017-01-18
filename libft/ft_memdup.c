/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:31:57 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/02 16:38:04 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	void *dst;

	if (src == NULL)
		return (NULL);
	dst = malloc(n);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, n);
	return (dst);
}
