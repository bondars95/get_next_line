/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarrsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:49:12 by apalanic          #+#    #+#             */
/*   Updated: 2016/12/06 10:20:59 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intarrsort(int *arr, size_t n)
{
	size_t	i;
	size_t	j;
	int		tmp;

	if (n == 0 || arr == NULL)
		return (NULL);
	i = 1;
	while (i < n)
	{
		j = i;
		while (j > 0 && (arr[j - 1] > arr[j]))
		{
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			j--;
		}
		i++;
	}
	return (arr);
}
