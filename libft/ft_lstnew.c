/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:43:15 by tstaes-           #+#    #+#             */
/*   Updated: 2016/11/26 01:22:02 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
		list->next = NULL;
		return (list);
	}
	if (!(list->content = malloc(sizeof(content))))
		return (NULL);
	ft_memcpy(list->content, content, content_size);
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
