/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:28:36 by apalanic          #+#    #+#             */
/*   Updated: 2016/11/26 14:59:44 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(int num)
{
	size_t i;

	i = 1;
	if (num == -2147483648)
		return (11);
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num / 10 > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = count_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str[len] = '\0';
	while (n > 0)
	{
		str[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
