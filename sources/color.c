/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:41:21 by tstaes-           #+#    #+#             */
/*   Updated: 2017/04/06 14:31:59 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	ft_get_color(int i, t_env *e)
{
	unsigned int	color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (i == e->imax)
		return (e->color_max);
	r = i * e->cr;
	g = i * e->cg;
	b = i * e->cb;
	color = (r << 16) + (g << 8) + b;
	return (color);
}

void			put_pixel(t_env *e, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < e->width && y >= 0 && y < e->height)
	{
		i = (x * 4) + (y * e->s_l);
		e->my_image_string[i] = color;
		e->my_image_string[++i] = color >> 8;
		e->my_image_string[++i] = color >> 16;
	}
}
