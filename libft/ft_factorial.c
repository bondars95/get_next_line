/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:56:23 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/02 16:01:27 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_factorial(int n)
{
	int f;

	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	else
	{
		f = ft_factorial(n - 1);
		if ((n * f) / n != f)
			return (0);
		return (n * f);
	}
}
