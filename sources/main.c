/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:41:21 by tstaes-           #+#    #+#             */
/*   Updated: 2017/05/22 19:31:23 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				ft_display_indications(t_env *e)
{
	if (e->indications % 2 == 0)
	{
		mlx_string_put(e->mlx, e->win, 10, 400, 0xFFFFFF,
			"Press esc to quit");
		mlx_string_put(e->mlx, e->win, 10, 420, 0xFFFFFF,
			"Press i to hide the indications");
		mlx_string_put(e->mlx, e->win, 10, 440, 0xFFFFFF,
			"ZOOM+ = '+' | ZOOM- = '-'");
		mlx_string_put(e->mlx, e->win, 10, 460, 0xFFFFFF,
			"Move left = LeftArrow | Move right = RightArrow");
		mlx_string_put(e->mlx, e->win, 10, 480, 0xFFFFFF,
			"Move up = UpArrow | Move down = DownArrow");
		mlx_string_put(e->mlx, e->win, 10, 500, 0xFFFFFF,
			"Precision+ = '*' | Precision- = '/'");
		mlx_string_put(e->mlx, e->win, 10, 520, 0xFFFFFF,
			"Press 1, 2, 3 to change CR, CG, CB | 4, 5, 6 for reset");
		mlx_string_put(e->mlx, e->win, 10, 540, 0xFFFFFF,
			"Move for Julia = 'q' | Fix for Julia = 'w'");
	}
	if (e->indications % 2 != 0)
		mlx_string_put(e->mlx, e->win, 10, 560, 0xFFFFFF,
		"Press i for indications");
	return (1);
}

void			do_it(t_env *e)
{
	mlx_key_hook(e->win, key_hook, e);
	mlx_hook(e->win, 6, 1 << 8, mouse_hook_move, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_put_image_to_window(e->mlx, e->win, e->pointeur_image, 0, 0);
	ft_display_indications(e);
	mlx_loop(e->mlx);
}

static int		verif_name_two(char *name, t_env *e)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
	{
		ft_init_env(e);
		mandelbrot(e);
		e->wich_fractal = 1;
	}
	else if (ft_strcmp(name, "julia") == 0)
	{
		ft_init_env(e);
		julia(e);
		e->wich_fractal = 2;
	}
	else if (ft_strcmp(name, "burningship") == 0)
	{
		ft_init_env(e);
		burningship(e);
		e->wich_fractal = 3;
	}
	else if (ft_strcmp(name, "axone") == 0 || ft_strcmp(name, "toto") == 0)
		return (0);
	else
		return (-1);
	return (0);
}

static void		verif_name(char *name, t_env *e)
{
	if (ft_strcmp(name, "axone") == 0)
	{
		ft_init_env(e);
		axone(e);
		e->wich_fractal = 4;
	}
	if (ft_strcmp(name, "toto") == 0)
	{
		ft_init_env(e);
		toto(e);
		e->wich_fractal = 5;
	}
	if (verif_name_two(name, e) == -1)
	{
		ft_putstr("ERROR : This fractal is unknow\n\n");
		ft_putstr("Usage : ./fractol <name of fractal>\n");
		ft_putstr("Name : mandelbrot, julia, burningship, axone, toto");
	}
}

int				main(int ac, char **av)
{
	t_env		e;

	if (ac == 2)
	{
		verif_name(av[1], &e);
		if (ft_strcmp(av[1], "mandelbrot") == 0
			|| ft_strcmp(av[1], "julia") == 0
			|| ft_strcmp(av[1], "burningship") == 0
			|| ft_strcmp(av[1], "axone") == 0
			|| ft_strcmp(av[1], "toto") == 0)
			do_it(&e);
	}
	else
	{
		ft_putstr("Usage : ./fractol <name of fractal>\n");
		ft_putstr("Name : mandelbrot, julia, burningship, axone, toto");
	}
	return (0);
}
