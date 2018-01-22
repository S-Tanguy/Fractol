/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:41:21 by tstaes-           #+#    #+#             */
/*   Updated: 2017/05/22 19:34:07 by tstaes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct		s_fractol
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zr;
	double		zi;
	double		cr;
	double		ci;
	double		tmp;
}					t_fractol;

typedef struct		s_env
{
	double		mouse_x;
	double		mouse_y;
	int			mouse_move;
	void		*mlx;
	void		*win;
	void		*pointeur_image;
	char		*my_image_string;
	int			endian;
	int			s_l;
	int			bpp;
	int			psy;
	int			itera_max;
	int			color_max;
	int			cr;
	int			cg;
	int			cb;
	int			imax;
	int			x;
	int			y;
	int			height;
	int			width;
	double		zoom;
	int			wich_fractal;
	int			color_value;
	int			indications;
	t_fractol	*mand;
}					t_env;

void				axone(t_env *e);
void				toto(t_env *e);
unsigned int		ft_get_color(int i, t_env *e);
void				put_pixel(t_env *e, int x, int y, int color);
void				mandelbrot(t_env *e);
t_fractol			*ft_init_fract(void);
void				*ft_init_env(t_env *e);
int					ft_init_env_fract(t_env *e);
void				julia(t_env *e);
void				burningship(t_env *e);
int					key_hook(int keycode, t_env *e);
void				make_fractal(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);
int					mouse_hook_move(int x, int y, t_env *e);
int					ft_display_indications(t_env *e);

#endif
