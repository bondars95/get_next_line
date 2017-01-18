/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:41:24 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/02 15:29:19 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*p_s1;
	const unsigned char	*p_s2;
	size_t				i;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	i = 0;
	while ((p_s1[i] != '\0' && p_s2[i] != '\0') && i < n)
	{
		if (p_s1[i] != p_s2[i])
			return ((int)(p_s1[i] - p_s2[i]));
		i++;
	}
	if ((p_s1[i] == 0 || p_s2[i] == 0) && (i != n))
		return ((int)(p_s1[i] - p_s2[i]));
	return (0);
}
