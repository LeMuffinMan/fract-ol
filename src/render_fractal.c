/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:30:45 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 19:26:02 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // remplacer pour printf
#include "../include/fractol.h"
#include <math.h>

void	set_complexes(int x, int y, t_data *f)
{
	f->z.x = 0.0;
	f->z.y = 0.0;
	if (f->fractal_number == 1)
	{
		f->c.x = (scale(x, -3, +3, 0, WINSIZE) * f->zoom) + f->shift_view.x;
		f->c.y = (scale(y, -3, +3, 0, WINSIZE) * f->zoom) - f->shift_view.y;
	}
	else if (f->fractal_number == 2)
	{
		f->c.x = f->julia_constant.x;
		f->c.y = f->julia_constant.y;
	}
}

/* void	debug(t_data *f) */
/* { */
/* 	printf("======================================\n"); */
/* 	printf("boucle t = %f\nj_x = %Lf\nj_y = %Lf\n", f->t, f->julia_constant.x, f->julia_constant.y); */
/* 	printf("shift_x = %.20Lf\n", f->shift_view.x); */
/* 	printf("shift_y = %.20Lf\n", f->shift_view.y); */
/* 	printf("a.x = %Lf\n", f->a.x); */
/* 	printf("a.y = %Lf\n", f->a.y); */
/* 	printf("o.x = %Lf\n", f->o.x); */
/* 	printf("o.y = %Lf\n", f->o.y); */
/* 	printf("multibrot power %f\n", f->power); */
/* 	printf("--------------------------------------\n"); */
/* 	printf("max_iterations = %Lf\n", f->max_iterations); */
/* 	printf("f->tc = %f\n", f->tc); */
/* 	printf("speed_factor = %f\n", f->speed_factor); */
/* 	printf("traveling = %d\n", f->flags.traveling); */
/* 	printf("--------------------------------------\n"); */
/* 	printf("f->zoom = %.20Lf\n", f->zoom); */
/* 	printf("f->flags.zooming_in = %d\n", f->flags.zooming_in); */
/* 	printf("f->flags.zooming_out = %d\n", f->flags.zooming_out); */
/* 	printf("--------------------------------------\n"); */
/* 	printf("f->flags.psyche_switch = %d\n", f->flags.psyche_switch); */
/* 	printf("psychedelic_colors = %d\n", f->flags.psychedelic_colors); */
/* } */

void	iterate_on_pixels(t_data *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINSIZE)
	{
		x = 0;
		while (x < WINSIZE)
		{
			set_complexes(x, y, f);
			render_fractal(x, y, f);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img.img_p, 0, 0);
}

void	bit_shift_rgb(int i, int *color, t_data *f)
{
	t_color	colors;
	double	t;

	t = (double)i / f->max_iterations;
		colors.r = (char)(9 * (1 - t) * t * t * t * t * 255);
		colors.g = (char)(15 * (1 - t) * (1 - t) * t * t * 255);
		colors.b = (char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	*color = colors.color;
}

void	render_fractal(int x, int y, t_data *f)
{
	int	i;
	int	color;

	i = 0;
	while (i < f->max_iterations)
	{
		calculate_f(f);
		if ((f->z.x * f->z.x) + (f->z.y * f->z.y) > f->escape_value)
		{
			bit_shift_rgb(i, &color, f);
			colorize_pixel(x, y, &f->mlx.img, color);
			return ;
		}
		i++;
	}
	colorize_pixel(x, y, &f->mlx.img, BLACK);
}
