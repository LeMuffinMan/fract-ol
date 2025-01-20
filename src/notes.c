/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   c.xeated: 2025/01/19 19:08:05 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/19 19:09:26 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <math.h>
#include <stdlib.h>


void	template(int x, int y, t_fractal *f)
{
	/* t_complex	z; */
	/* t_complex	c; */
	int			i;
	int			color;
	/* double 	mu; */

	i = 0;
	// parce que z0 = 0 ET que z est reel et n'est pas dans le plan complexe
	/* f->z.x = 0.0; */
	/* f->z.y = 0.0; */
	/* init_mandelbrot(f); */
	// parce que z = a + bi // z = x + yi
	// on veut savoir ou se situe c sur le plan complex ?
	f->c.x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_x;
	f->c.y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->zoom) + f->shift_y;
	while (i < f->max_iterations)
	{
		// z = result of addition of a real (r) and an imaginary (c) number
		// c = imaginary number
		f->z = sum_complex(square_complex(f->z), f->c);
		// value escaped ? hypothenus > 2
		// Here we can't compute to infinity but it's safe to say that if the
		/* absolute value of Z goes above 2, it will tend toward infinity and */
		/* the number won't be part of the Mandelbrot set. */
		if ((f->z.x * f->z.x) + (f->z.y * f->z.y) > f->escape_value)
		{
      /* color = generate_combined_color(i, f->max_iterations); */
	  	f->mu = log(log(norm_complex(f->z))) / log(2);
		  color = generate_smooth_color(i, f->mu, f->max_iterations);
			colorize_pixel(x, y, &f->img, color);
			return ;
		}
		i++;
	}
	colorize_pixel(x, y, &f->img, BLACK);
}

/* void	julia(int x, int y, t_fractal *f) */
/* { */
/* 	t_complex	z; */
/* 	t_complex	c; */
/* 	int			i; */
/* 	int			color; */
/* 	double mu; */
/**/
/* 	i = 0; */
/* 	z.x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_x; */
/* 	z.y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->zoom) + f->shift_y; */
/* 	//capter pourquoi ic.y c est z qu'on scale */
/**/
/* 	c.x = f->j_x; //-0.8; */
/* 	c.y = f->j_y; //0.156; */
/* 	 */
/* 	while (i < f->max_iterations) */
/* 	{ */
/* 		z = sum_complex(square_complex(z), c); */
/* 		if ((z.x * z.x) + (z.y * z.y) > f->escape_value) */
/* 		{ */
/*       mu = log(log(norm_complex(z))) / log(2); */
/* 	    color = generate_smooth_color(i, mu, f->max_iterations); */
/*       colorize_pixel(x, y, &f->img, color); */
/* 			return ; */
/* 		} */
/* 		i++; */
/* 	} */
/* 	colorize_pixel(x, y, &f->img, BLACK); */
/* } */

/* void	burning_ship(int x, int y, t_fractal *f) */
/* { */
/* 	t_complex	z; */
/* 	t_complex	c; */
/* 	int			i; */
/* 	int			color; */
/* 	double tmp; */
/* 	double mu; */
/**/
/* 	i = 0; */
/* 	// parce que z0 = 0 ET que z est reel et n'est pas dans le plan complexe */
/* 	z.x = 0.0; */
/* 	z.y = 0.0; */
/* 	// parce que z = a + bi // z = x + yi */
/* 	// on veut savoir ou se situe c sur le plan complex ? */
/* 	c.x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_x; */
/* 	c.y = (scale(y, -3, +3, 0, WINSIZE_Y) * f->zoom) - f->shift_y; */
/* 	while (i < f->max_iterations) */
/* 	{ */
/* 		if ((z.x * z.x) + (z.y * z.y) > f->escape_value) */
/* 		{ */
/**/
/* 			break ; */
/* 		} */
/* 		z.x = fabs(z.x); */
/* 		z.y = fabs(z.y); */
/* 		tmp = 2 * z.x * z.y + c.y; */
/* 		z.x = z.x * z.x - z.y * z.y + c.x; */
/* 		z.y = tmp; */
/* 		i++;	 */
/* 	} */
/* 	if (i > f->escape_value) */
/* 	{ */
/*   	mu = log(log(norm_complex(z))) / log(2); */
/* 	  color = generate_smooth_color(i, mu, f->max_iterations); */
/* 		colorize_pixel(x, y, &f->img, color); */
/* 	} */
/* 	else */
/* 		colorize_pixel(x, y, &f->img, BLACK); */
/* } */
/**/
/* void	tricorn(int x, int y, t_fractal *f) */
/* { */
/* 	t_complex	z; */
/* 	t_complex	c; */
/* 	int			i; */
/* 	int			color; */
/* 	double tmp; */
/* 	double mu; */
/**/
/* 	i = 0; */
/* 	z.x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_x; */
/* 	z.y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->zoom) + f->shift_y; */
/* 	//capter pourquoi ic.y c est z qu'on scale */
/**/
/* 	c.x = z.x; //-0.8; */
/* 	c.y = z.y; //0.156; */
/* 	while (i < f->max_iterations) */
/* 	{ */
/* 		if ((z.x * z.x + z.y * z.y) > 4.0) */
/* 			break ; */
/* 		tmp = -2 * z.x * z.y + c.y; */
/* 		z.x = z.x * z.x - z.y * z.y + c.x; */
/* 		z.y = tmp; */
/* 		i++; */
/* 	} */
/* 	if (i > f->escape_value) */
/* 	{ */
/*   	mu = log(log(norm_complex(z))) / log(2); */
/* 	  color = generate_smooth_color(i, mu, f->max_iterations); */
/* 		colorize_pixel(x, y, &f->img, color); */
/* 	} */
/* 	else */
/* 		colorize_pixel(x, y, &f->img, BLACK); */
/* } */
/**/
