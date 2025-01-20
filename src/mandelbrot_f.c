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

double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max) //a reec.xire
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

void colorize_pixel(int x, int y, t_img *img, int color) //degrader a gerer ic.y ?
//je capte pas ce que je fais la 
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp));
	*(unsigned int *)(img->pixels + offset) = color;
}

/**
 * Interpolation linéaire entre deux couleurs
 */
int interpolate_color(int color1, int color2, double t)
{
    int r = ((1 - t) * ((color1 >> 16) & 0xFF)) + (t * ((color2 >> 16) & 0xFF));
    int g = ((1 - t) * ((color1 >> 8) & 0xFF)) + (t * ((color2 >> 8) & 0xFF));
    int b = ((1 - t) * (color1 & 0xFF)) + (t * (color2 & 0xFF));
    return (r << 16) | (g << 8) | b;
}

/**
 * Palette prédéfinie
 */
int palette[] = {
    /* 0xFF0000, // Rouge */
    /* 0xFF7F00, // Orange */
    /* 0xFFFF00 // Jaune */
    0x00FF00, // Vert
    0x0000FF, // Bleu
    0x4B0082, // Indigo
    0x8B00FF  // Violet
};

/**
 * Générer une couleur psychédélique avec une palette et interpolation
 */
int generate_psychedelic_color(int iteration, int max_iterations)
{
    double t = (double)iteration / max_iterations;
    int palette_size = sizeof(palette) / sizeof(int);

    // Couleurs de la palette en fonction des itérations
    int color1 = palette[iteration % palette_size];
    int color2 = palette[(iteration + 1) % palette_size];

    // Appliquer une interpolation linéaire pour des transitions douces
    return interpolate_color(color1, color2, fmod(t * palette_size, 1.0));
}

/**
 * Générer une couleur cyclique avec des fonctions sinus/cosinus
 */
int generate_cyclic_color(int iteration, int max_iterations)
{
    double t = (double)iteration / max_iterations;
    int r = (int)(128 * (1 + sin(6.28318 * t)));         // Sinus pour des transitions douces
    int g = (int)(128 * (1 + sin(6.28318 * t + 2.0)));   // Décalage de phase
    int b = (int)(128 * (1 + sin(6.28318 * t + 4.0)));   // Décalage de phase
    return (r << 16) | (g << 8) | b;
}

/**
 * Mélanger les deux approches pour un effet unique
 */
int generate_combined_color(int iteration, int max_iterations)
{
    int psychedelic_color = generate_psychedelic_color(iteration, max_iterations);
    int cyclic_color = generate_cyclic_color(iteration, max_iterations);

    // Mélange des deux couleurs (50% de chaque)
    return interpolate_color(psychedelic_color, cyclic_color, 0.5);
}

//A TESTER 
/* int generate_coordinate_based_color(t_complex z, int max_iterations) */
/* { */
/*     double norm = sqrt(z.x * z.x + z.y * z.y); */
/*     int r = (int)(128 * (1 + sin(norm * 6.28318))); */
/*     int g = (int)(128 * (1 + sin(norm * 6.28318 + 2.0))); */
/*     int b = (int)(128 * (1 + sin(norm * 6.28318 + 4.0))); */
/*     return (r << 16) | (g << 8) | b; */
/* } */


double norm_complex(t_complex z)
{
    return sqrt(z.x * z.x + z.y * z.y);
}

int generate_smooth_color(int iteration, double mu, int max_iterations)
{
    double t = (iteration + 1 - mu) / max_iterations; // Fraction lissée
    int palette_size = sizeof(palette) / sizeof(int);

    int color1 = palette[(int)(t * palette_size) % palette_size];
    int color2 = palette[((int)(t * palette_size) + 1) % palette_size];

    return interpolate_color(color1, color2, fmod(t * palette_size, 1.0));
}



void calculate_f(t_fractal *f)
{
	double tmp;

	if (f->fractal_number == 1 || f->fractal_number == 2)
		f->z = sum_complex(square_complex(f->z), f->c);
	if (f->fractal_number == 3)
	{
		f->z.x = fabs(f->z.x);
		f->z.y = fabs(f->z.y);
		tmp = 2 * f->z.x * f->z.y + f->c.y;
		f->z.x = f->z.x * f->z.x - f->z.y * f->z.y + f->c.x;
		f->z.y = tmp;
	}
	if (f->fractal_number == 4)
	{
		tmp = -2 * f->z.x * f->z.y + f->c.y;
		f->z.x = f->z.x * f->z.x - f->z.y * f->z.y + f->c.x;
		f->z.y = tmp;
	}
}

void	render_fractal(int x, int y, t_fractal *f)
{
	int			i;
	int			color;

	i = 0;
	while (i < f->max_iterations)
	{
		calculate_f(f);
		if ((f->z.x * f->z.x) + (f->z.y * f->z.y) > f->escape_value)
		{
	  	f->mu = log(log(norm_complex(f->z))) / log(2);
		  color = generate_smooth_color(i, f->mu, f->max_iterations);
			colorize_pixel(x, y, &f->img, color);
			return ;
		}
		i++;
	}
	colorize_pixel(x, y, &f->img, BLACK);
}

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
