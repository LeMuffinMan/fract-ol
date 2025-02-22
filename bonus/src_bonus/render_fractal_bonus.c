/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:30:45 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/22 10:31:24 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/fractol_bonus.h"
#include <math.h>
#include <stdio.h> // remplacer pour printf

void	set_complexes(int x, int y, t_data *f)
{
	f->z.x = 0.0;
	f->z.y = 0.0;
	if (f->fractal_number == 2 || f->fractal_number == 7
		|| f->fractal_number == 1 || f->fractal_number == 9)
	{
		f->c.x = (scale(x, -3, +3, WINSIZE_X) * f->zoom) + f->shift_view.x;
		f->c.y = (scale(y, -3, +3, WINSIZE_Y) * f->zoom) - f->shift_view.y;
	}
	else if (f->fractal_number == 3)
	{
		f->c.x = (scale(x, -3, +3, WINSIZE_X) * f->zoom) + f->shift_view.x;
		f->c.y = (scale(y, +3, -3, WINSIZE_Y) * f->zoom) + f->shift_view.y;
	}
	else if (f->fractal_number == 4 || f->fractal_number == 5
		|| f->fractal_number == 6 || f->fractal_number == 8)
	{
		f->z.x = (scale(x, -3, +3, WINSIZE_X) * f->zoom) + f->shift_view.x;
		f->z.y = (scale(y, +3, -3, WINSIZE_Y) * f->zoom) + f->shift_view.y;
		f->c.x = f->julia_constant.x;
		f->c.y = f->julia_constant.y;
	}
}

void	debug(t_data *f)
{
	printf("======================================\n");
	printf("boucle t = %f\nj_x = %Lf\nj_y = %Lf\n", f->t, f->julia_constant.x,
		f->julia_constant.y);
	printf("shift_x = %.20Lf\n", f->shift_view.x);
	printf("shift_y = %.20Lf\n", f->shift_view.y);
	printf("a.x = %Lf\n", f->a.x);
	printf("a.y = %Lf\n", f->a.y);
	printf("o.x = %Lf\n", f->o.x);
	printf("o.y = %Lf\n", f->o.y);
	printf("multibrot power %f\n", f->power);
	printf("--------------------------------------\n");
	printf("max_iterations = %Lf\n", f->max_iterations);
	printf("f->tc = %f\n", f->tc);
	printf("speed_factor = %f\n", f->speed_factor);
	printf("traveling = %d\n", f->flags.traveling);
	printf("--------------------------------------\n");
	printf("f->zoom = %.20Lf\n", f->zoom);
	printf("f->flags.zooming_in = %d\n", f->flags.zooming_in);
	printf("f->flags.zooming_out = %d\n", f->flags.zooming_out);
	printf("--------------------------------------\n");
	printf("f->flags.psyche_switch = %d\n", f->flags.psyche_switch);
	printf("psychedelic_colors = %d\n", f->flags.psychedelic_colors);
}

void	iterate_on_pixels(t_data *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINSIZE_Y)
	{
		x = 0;
		while (x < WINSIZE_X)
		{
			set_complexes(x, y, f);
			render_fractal(x, y, f);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img.img_p, 0, 0);
	if (f->flags.debug == 1)
		debug(f);
}

void	render_fractal(int x, int y, t_data *f)
{
	int			i;
	int			color;
	t_coords	coords;

	i = 0;
	color = 0;
	while (i < f->max_iterations)
	{
		calculate_f(f);
		t_coords.x = x;
		t_coords.y = y;
		if (colorize_pixel(coords, f, color, i))
			return ;
		i++;
	}
	if (f->flags.psyche_switch == 1)
		color = BLACK;
	else
		*(unsigned int *)(f->mlx.img.pixels + (y * f->mlx.img.line_len) + (x
					* (f->mlx.img.bpp))) = BLACK;
}
