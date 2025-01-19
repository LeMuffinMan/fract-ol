/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:08:05 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/19 19:09:26 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <math.h>
#include <stdlib.h>

double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max) //a reecrire
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

void colorize_pixel(int x, int y, t_img *img, int color) //degrader a gerer ici ?
//je capte pas ce que je fais la 
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp));
	*(unsigned int *)(img->pixels + offset) = color;
}

/* double abs_complex(t_complex z) { */
/*     return sqrt(z.x * z.x + z.y * z.y); */
/* } */

void	mandelbrot_f(int x, int y, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	// parce que z0 = 0 ET que z est reel et n'est pas dans le plan complexe
	z.x = 0.0;
	z.y = 0.0;
	// parce que z = a + bi // z = x + yi
	// on veut savoir ou se situe c sur le plan complex ?
	c.x = scale(x, -3, +3, 0, WINSIZE * f->zoom) + f->shift_x;
	c.y = scale(y, +3, -3, 0, WINSIZE * f->zoom) + f->shift_y;
	while (i < f->max_iterations)
	{
		// z = result of addition of a real (r) and an imaginary (c) number
		// c = imaginary number
		z = sum_complex(square_complex(z), c);
		// value escaped ? hypothenus > 2
		// Here we can't compute to infinity but it's safe to say that if the
		/* absolute value of Z goes above 2, it will tend toward infinity and */
		/* the number won't be part of the Mandelbrot set. */
		if ((z.x * z.x) + (z.y * z.y) > f->escape_value)
		{
			color = scale((i + 1 - log(log2(abs_complex(z)))), PURE_BLUE, PURE_GREEN, 0, f->max_iterations);
			colorize_pixel(x, y, &f->img, color);
			return ;
		}
		i++;
	}
	colorize_pixel(x, y, &f->img, BLACK);
}
