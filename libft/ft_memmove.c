/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:51:18 by tstaes-           #+#    #+#             */
/*   Updated: 2016/11/18 11:27:15 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, int n)
{
	unsigned char *str;

	str = (unsigned char *)malloc(sizeof(*str) * n);
	if (str)
	{
		ft_memcpy(str, s2, n);
		ft_memcpy(s1, str, n);
		free(str);
	}
	return (s1);
}
