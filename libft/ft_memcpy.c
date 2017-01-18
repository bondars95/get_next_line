/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:51:55 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/02 14:30:28 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p_d;
	const unsigned char	*p_s;
	size_t				i;

	i = 0;
	p_d = (unsigned char *)dst;
	p_s = (const unsigned char *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (i < n)
	{
		ft_memset(&p_d[i], p_s[i], 1);
		i++;
	}
	return (dst);
}
