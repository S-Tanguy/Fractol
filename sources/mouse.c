/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:41:21 by tstaes-           #+#    #+#             */
/*   Updated: 2017/05/22 15:12:36 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 6 && x > 0 && y > 0)
	{
		e->imax += 1;
		if (y > 0)
			e->mand->y1 += 0.6666 * (HEIGHT * (e->zoom / 10) / (e->zoom *
			(e->zoom - (e->zoom / 10)))) / ((HEIGHT / y) / (WIDTH / HEIGHT));
		if (x > 0)
			e->mand->x1 += 0.6666 * (WIDTH * (e->zoom / 10) / (e->zoom *
			(e->zoom - (e->zoom / 10)))) / ((WIDTH / x) / (WIDTH / HEIGHT));
		e->zoom += (e->zoom / 10);
	}
	if (button == 7 && x > 0 && y > 0 && e->zoom > 30)
	{
		e->imax -= 1;
		if (y > 0)
			e->mand->y1 -= 0.6666 * (HEIGHT * (e->zoom / 10) / (e->zoom *
			(e->zoom - (e->zoom / 10)))) / ((HEIGHT / y) / (WIDTH / HEIGHT));
		if (x > 0)
			e->mand->x1 -= 0.6666 * (WIDTH * (e->zoom / 10) / (e->zoom *
			(e->zoom - (e->zoom / 10)))) / ((WIDTH / x) / (WIDTH / HEIGHT));
		e->zoom -= (e->zoom / 10);
	}
	mlx_clear_window(e->mlx, e->win);
	make_fractal(e);
	return (0);
}

int		mouse_hook_move(int x, int y, t_env *e)
{
	if (e->mouse_move == 1 && x < WIDTH && x > 0 && y < HEIGHT && y > 0)
	{
		e->mouse_x = (x - WIDTH / 2.0) / WIDTH * 4;
		e->mouse_y = (y - HEIGHT / 2.0) / HEIGHT * 4;
	}
	mlx_clear_window(e->mlx, e->win);
	make_fractal(e);
	return (0);
}
