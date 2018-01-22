/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 00:49:27 by tstaes-           #+#    #+#             */
/*   Updated: 2016/11/18 11:20:35 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char a;
	char *str;

	a = (char)c;
	str = NULL;
	while (*s != '\0')
	{
		if (*s == a)
			str = (char *)s;
		s++;
	}
	if (*s == '\0' && (char)c == '\0')
		return ((char *)s);
	return (str);
}
