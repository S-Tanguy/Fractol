/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 23:26:59 by tstaes-           #+#    #+#             */
/*   Updated: 2016/11/18 11:28:24 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, int n)
{
	int					i;
	unsigned int		res;
	const unsigned char	*s1bis;
	const unsigned char	*s2bis;

	if (!s1 && !s2)
		return (0);
	s1bis = (const unsigned char *)s1;
	s2bis = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1bis[i] != s2bis[i])
		{
			res = s1bis[i] - s2bis[i];
			return (res);
		}
		i++;
	}
	return (0);
}
