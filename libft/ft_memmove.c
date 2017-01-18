/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:58:34 by apalanic          #+#    #+#             */
/*   Updated: 2016/11/25 13:04:05 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p_d;
	const unsigned char	*p_s;
	size_t				i;

	p_d = (unsigned char *)dst;
	p_s = (const unsigned char *)src;
	if ((p_d - p_s) >= 0)
	{
		i = len;
		while (i != 0)
		{
			p_d[i - 1] = p_s[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			p_d[i] = p_s[i];
			i++;
		}
	}
	return (dst);
}
