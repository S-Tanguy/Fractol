/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:41:21 by tstaes-           #+#    #+#             */
/*   Updated: 2017/05/22 15:23:36 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		ft_julia_iter(t_env *e)
{
	int			i;

	i = 0;
	while (i < e->imax)
	{
		e->mand->tmp = e->mand->zr;
		e->mand->zr = e->mand->zr * e->mand->zr - e->mand->zi * e->mand->zi +
			e->mand->cr;
		e->mand->zi = 2 * e->mand->zi * e->mand->tmp + e->mand->ci;
		if (e->mand->zr * e->mand->zr + e->mand->zi * e->mand->zi >= 4)
			return (i);
		i++;
	}
	return (i);
}

void			julia(t_env *e)
{
	double		x;
	double		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			e->mand->zr = (double)x / e->zoom + e->mand->x1;
			e->mand->zi = (double)y / e->zoom + e->mand->y1;
			e->mand->cr = e->mouse_x;
			e->mand->ci = e->mouse_y;
			put_pixel(e, x, y,
				ft_get_color(ft_julia_iter(e), e));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->pointeur_image, 0, 0);
}
