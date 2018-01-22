/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:13:55 by tstaes-           #+#    #+#             */
/*   Updated: 2016/11/18 11:23:18 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, int n)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (i < n && str[i] != '\0')
	{
		j = i;
		c = 0;
		while (str[j] == to_find[c])
		{
			j++;
			c++;
			if (to_find[c] == '\0' && j <= n)
				return (char*)(&str[i]);
		}
		i++;
	}
	return (NULL);
}
