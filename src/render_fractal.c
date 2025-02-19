/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:30:45 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/19 15:19:22 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // remplacer pour printf
#include "../include/fractol.h"
#include <math.h>

//optimiser les calculs ?
//renommer les fonctions

//a mettre en static ?
void	set_complexes(int x, int y, t_data *f)
{
	if (f->fractal_number == 1)
	{
		f->z.x = 0.0;
		f->z.y = 0.0;
		f->c.x = (scale(x, -3, +3, 0, WINSIZE) * f->zoom) + f->shift_view.x;
		f->c.y = (scale(y, -3, +3, 0, WINSIZE) * f->zoom) - f->shift_view.y;
	}
	else if (f->fractal_number == 2)
	{
		f->z.x = (scale(x, -3, +3, 0, WINSIZE) * f->zoom) + f->shift_view.x;
		f->z.y = (scale(y, -3, +3, 0, WINSIZE) * f->zoom) - f->shift_view.y;
		f->c.x = f->julia_constant.x;
		f->c.y = f->julia_constant.y;
	}
}

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
	//lire la doc
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img.img_p, 0, 0);
	//virer le do_sync ?
	mlx_do_sync(f->mlx.mlx);
}

//renommer et potasser 
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
		f->z = sum_complex(square_complex(f->z), f->c);
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

// lire la doc pour ca !
// faire un fichier avec les fonctions speciales minilibx
void	colorize_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp));
	*(unsigned int *)(img->pixels + offset) = color;
}


