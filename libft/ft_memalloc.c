/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:05:22 by tstaes-           #+#    #+#             */
/*   Updated: 2016/11/15 22:22:16 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *memo;

	memo = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (memo == NULL)
		return (NULL);
	ft_bzero(memo, size);
	return (memo);
}
