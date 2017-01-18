/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:37:41 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/02 16:42:37 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int n, int power)
{
	if (power == 0)
		return (1);
	if (n == 0 || power < 0)
		return (0);
	else if (power > 0)
		return (n * ft_power(n, power - 1));
	else
		return (1);
}
