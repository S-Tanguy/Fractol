/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:41:21 by tstaes-           #+#    #+#             */
/*   Updated: 2017/05/22 19:32:39 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			make_fractal(t_env *e)
{
	if (e->wich_fractal == 1)
		mandelbrot(e);
	if (e->wich_fractal == 2)
		julia(e);
	if (e->wich_fractal == 3)
		burningship(e);
	if (e->wich_fractal == 4)
		axone(e);
	if (e->wich_fractal == 5)
		toto(e);
	ft_display_indications(e);
}

t_fractol		*ft_init_fract(void)
{
	t_fractol	*fract;

	if (!(fract = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		return (NULL);
	fract->x1 = -2.1;
	fract->x2 = 0.6;
	fract->y1 = -1.2;
	fract->y2 = 1.2;
	fract->zr = 0;
	fract->zi = 0;
	fract->cr = 0;
	fract->ci = 0;
	fract->tmp = 0;
	return (fract);
}

int				ft_init_env_fract(t_env *e)
{
	if (!(e->mand = ft_init_fract()))
		return (0);
	return (1);
}

void			*ft_init_env(t_env *e)
{
	e->mouse_x = 0.285;
	e->mouse_y = 0.52;
	e->mouse_move = 0;
	e->width = WIDTH;
	e->height = HEIGHT;
	e->x = -WIDTH / 2;
	e->y = -HEIGHT / 2;
	e->zoom = 250;
	e->color_max = 0x000000;
	e->mlx = mlx_init();
	e->imax = 25;
	e->color_value = 1;
	e->cr = 5;
	e->cg = 10;
	e->cb = 2;
	e->indications = 0;
	e->pointeur_image = mlx_new_image(e->mlx, e->width, e->height);
	e->my_image_string = mlx_get_data_addr(e->pointeur_image, &(e->bpp),
											&(e->s_l), &(e->endian));
	if (!(ft_init_env_fract(e)))
		return (NULL);
	e->win = mlx_new_window(e->mlx, e->width, e->height, "Fract'ol");
	return (e);
}
