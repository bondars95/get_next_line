/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:18:41 by apalanic          #+#    #+#             */
/*   Updated: 2016/11/25 13:22:49 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char *p_s1;
	const unsigned char *p_s2;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	while ((*p_s1 != '\0' && *p_s2 != '\0') && *p_s1 == *p_s2)
	{
		p_s1++;
		p_s2++;
	}
	return (*p_s1 - *p_s2);
}
