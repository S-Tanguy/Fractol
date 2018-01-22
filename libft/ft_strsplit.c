/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 00:08:20 by tstaes-           #+#    #+#             */
/*   Updated: 2016/11/24 16:58:14 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	how_many_w(char *s, char c)
{
	int nb_words;
	int i;

	i = 0;
	nb_words = 0;
	while (s && *(s + i))
	{
		while (*(s + i) && *(s + i) == c)
			i++;
		if (*(s + i))
			nb_words++;
		while (*(s + i) && *(s + i) != c)
			i++;
	}
	return (nb_words);
}

static int	size_word(const char *s, char c)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**table;
	int		nb_word;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	nb_word = how_many_w((char *)s, c);
	table = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (!table)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		table[i] = ft_strsub((const char *)s, 0, size_word((const char *)s, c));
		if (!table[i])
			return (NULL);
		s = s + size_word(s, c);
		i++;
	}
	table[i] = NULL;
	return (table);
}
