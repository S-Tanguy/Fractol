/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 03:02:00 by tstaes-           #+#    #+#             */
/*   Updated: 2016/12/17 15:35:34 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			search_bs(char *stk)
{
	int				i;

	i = 0;
	while (stk[i] != '\n' && stk[i] != '\0')
		i++;
	return (i);
}

static char			*analyse_stk(char *stk)
{
	char			*result;
	char			c;
	int				i;

	if (ft_strchr(stk, '\n') == NULL)
		return (ft_strdup(stk));
	i = search_bs(stk);
	c = stk[i];
	stk[i] = '\0';
	result = ft_strdup(stk);
	stk[i] = c;
	return (result);
}

int					get_next_line(int fd, char **line)
{
	static char		*stk = NULL;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				nbread;

	if (line == NULL)
		return (-1);
	stk = (!stk) ? ft_strnew(1) : stk;
	nbread = 1;
	while (!(ft_strchr(stk, '\n')) && nbread != 0)
	{
		if ((nbread = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[nbread] = '\0';
		tmp = stk;
		stk = ft_strjoin(stk, buf);
		free(tmp);
		if (nbread == 0 && stk[0] == '\0')
			return (0);
	}
	*line = analyse_stk(stk);
	tmp = stk;
	stk = ft_strdup((ft_strchr(stk, '\n')) ? ft_strchr(stk, '\n') + 1 : NULL);
	free(tmp);
	return (1);
}
