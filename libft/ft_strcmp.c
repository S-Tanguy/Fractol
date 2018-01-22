/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:05:52 by tstaes-           #+#    #+#             */
/*   Updated: 2016/11/15 23:32:27 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (s1[i] == s2[i] && s1[i + 1] == '\0' && s2[i + 1] == '\0')
			return (0);
		if (s1[i] != s2[i])
			return (res);
		i++;
	}
	return (0);
}