/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:30:45 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/19 16:02:18 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../minilibx-linux/mlx.h"

// revoir inline
inline static double	scale(double unscaled_num, double new_min,
		double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num) / old_max + new_min);
}

static void	set_complexes(int x, int y, t_data *f)
{
	if (f->fractal_number == 1)
	{
		f->z.x = 0.0;
		f->z.y = 0.0;
		f->c.x = (scale(x, -3, +3, WINSIZE) * f->zoom) + f->shift_view.x;
		f->c.y = (scale(y, -3, +3, WINSIZE) * f->zoom) - f->shift_view.y;
	}
	else if (f->fractal_number == 2)
	{
		f->z.x = (scale(x, -3, +3, WINSIZE) * f->zoom) + f->shift_view.x;
		f->z.y = (scale(y, -3, +3, WINSIZE) * f->zoom) - f->shift_view.y;
		f->c.x = f->julia_constant.x;
		f->c.y = f->julia_constant.y;
	}
}

// renommer et potasser
inline static void	bit_shift_rgb(int i, int *color, t_data *f)
{
	t_color	colors;
	double	t;

	t = (double)i / f->max_iterations;
	colors.r = (char)(9 * (1 - t) * t * t * t * t * 255);
	colors.g = (char)(15 * (1 - t) * (1 - t) * t * t * 255);
	colors.b = (char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	*color = colors.color;
}

static void	iterate_on_pixels(int x, int y, t_data *f)
{
	int			i;
	int			color;
	t_coords	z_squared;

	i = 0;
	while (i < f->max_iterations)
	{
		z_squared.x = (f->z.x * f->z.x) - (f->z.y * f->z.y);
		z_squared.y = 2 * f->z.x * f->z.y;
		f->z.x = z_squared.x + f->c.x;
		f->z.y = z_squared.y + f->c.y;
		if ((f->z.x * f->z.x) + (f->z.y * f->z.y) > f->escape_value)
		{
			bit_shift_rgb(i, &color, f);
			*(unsigned int *)(f->mlx.img.pixels + (y * f->mlx.img.line_len) + (x
						* (f->mlx.img.bpp))) = color;
			return ;
		}
		i++;
	}
	*(unsigned int *)(f->mlx.img.pixels + (y * f->mlx.img.line_len) + (x
				* (f->mlx.img.bpp))) = BLACK;
}

	// lire la doc
void	render_fractal(t_data *f)
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
			iterate_on_pixels(x, y, f);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img.img_p, 0, 0);
}
