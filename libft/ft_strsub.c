/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:29:01 by tstaes-           #+#    #+#             */
/*   Updated: 2016/11/23 01:41:37 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char					*memo;
	size_t					i;

	if (!s)
		return (NULL);
	memo = (char *)malloc(sizeof(char) * (len + 1));
	if (!memo)
		return (NULL);
	i = 0;
	while (i < len)
	{
		memo[i] = s[start];
		i++;
		start++;
	}
	memo[i] = '\0';
	return (memo);
}
