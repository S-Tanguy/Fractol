/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:04:59 by tstaes-           #+#    #+#             */
/*   Updated: 2016/11/15 22:21:00 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, int n)
{
	unsigned char	*t;

	if (n == 0)
		return (s);
	t = (unsigned char *)s;
	while (n--)
	{
		*t = (unsigned char)c;
		if (n)
			t++;
	}
	return (s);
}
