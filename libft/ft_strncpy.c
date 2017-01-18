/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:11:20 by apalanic          #+#    #+#             */
/*   Updated: 2016/11/25 13:49:35 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	size_src;
	size_t	i;

	i = 0;
	size_src = ft_strlen(src);
	while (i < size_src && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	if (size_src < len)
		while (i < len)
			dst[i++] = '\0';
	return (dst);
}
