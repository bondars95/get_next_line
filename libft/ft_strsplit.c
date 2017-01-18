/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apalanic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 10:18:29 by apalanic          #+#    #+#             */
/*   Updated: 2016/11/29 16:19:42 by apalanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordlen(const char *s, char c)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0' && s[size] != c)
		size++;
	return (size);
}

static size_t	wordcnt(const char *s, char c)
{
	size_t	i;
	size_t	wd_count;

	i = 0;
	wd_count = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c) && s[i] != '\0')
			i++;
		if (s[i])
			wd_count++;
		while (!(s[i] == c) && s[i] != '\0')
			i++;
	}
	return (wd_count);
}

static char		*wordp(const char *s, size_t wd_length)
{
	char	*word;
	size_t	i;

	i = 0;
	if ((word = (char *)malloc(sizeof(char *) * (wd_length + 1))) == NULL)
		return (NULL);
	while (i < wd_length)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(char *) * (wordcnt(s, c) + 1))))
		return (NULL);
	while (i < wordcnt(s, c))
	{
		while ((s[j] == c))
			j++;
		if ((arr[i] = wordp(s + j, wordlen(s + j, c))) == NULL)
			return (NULL);
		while (s[j] != c && s[j])
			j++;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
