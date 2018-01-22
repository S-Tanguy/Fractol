/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:53:12 by tstaes-           #+#    #+#             */
/*   Updated: 2017/05/22 19:31:48 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void			key_hook_three(int keycode, t_env *e)
{
	if (keycode == 86)
		e->cg = 10;
	if (keycode == 87)
		e->cb = 2;
	if (keycode == 88)
		e->cr = 5;
	if (keycode == 83)
	{
		e->cr += 30;
		if (e->cr > 250)
			e->cr = 5;
	}
	if (keycode == 84)
	{
		e->cg += 30;
		if (e->cg > 250)
			e->cg = 10;
	}
	if (keycode == 85)
	{
		e->cb += 30;
		if (e->cb > 250)
			e->cb = 2;
	}
}

static void			key_hook_two(int keycode, t_env *e)
{
	if (keycode == 69)
	{
		e->zoom *= 1.2;
		e->imax += 1;
	}
	if (keycode == 78 && e->zoom > 30)
	{
		e->zoom /= 1.2;
		e->imax -= 1;
	}
	if (keycode == 67)
		e->imax += 1;
	if (keycode == 75)
		e->imax -= 1;
	if (e->zoom < 1.3)
		e->zoom = 1.3;
	if (e->imax < 1)
		e->imax = 1;
	if (e->imax == 2147483646)
		e->imax = 2147483645;
}

int					key_hook(int keycode, t_env *e)
{
	if (keycode == 12)
		e->mouse_move = 1;
	if (keycode == 13)
		e->mouse_move = 0;
	if (keycode == 34)
		e->indications++;
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == 123)
		e->mand->x1 -= 15 / e->zoom;
	if (keycode == 124)
		e->mand->x1 += 15 / e->zoom;
	if (keycode == 125)
		e->mand->y1 += 15 / e->zoom;
	if (keycode == 126)
		e->mand->y1 -= 15 / e->zoom;
	key_hook_three(keycode, e);
	key_hook_two(keycode, e);
	mlx_clear_window(e->mlx, e->win);
	make_fractal(e);
	return (0);
}
