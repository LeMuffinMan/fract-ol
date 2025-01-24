/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:39:54 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/23 18:30:27 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/* #include <stdlib.h> */
#include "../include/fractol.h"
#include <math.h> // a virer

int	julia_dynamic(int x, int y, t_fractal *f)
{
	/* printf("x = %d | y = %d\n", x, y); */
	if (f->fractal_number == 6 || f->fractal_number == 5
		|| f->fractal_number == 4)
	{
		f->mouse_x = (scale(x, -3, +3, 0, WINSIZE_X) * f->tmp_zoom)
			+ f->tmp_shift_x;
		f->mouse_y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->tmp_zoom)
			+ f->tmp_shift_y;
	}
	else
	{
		f->mouse_x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_x;
		f->mouse_y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->zoom) + f->shift_y;
	}
	return (0);
}

int static	wheel(int key, int x, int y, t_fractal *f)
{
	if (key == MOUSE_WHEEL_DOWN) // zoom normal
	{
		f->zoom *= 1.1;
		f->shift_x -= (x - WINSIZE_X / 2.0) * f->zoom / 1000;
		f->shift_y += (y - WINSIZE_Y / 2.0) * f->zoom / 1000;
		return (1);
	}
	else if (key == MOUSE_WHEEL_UP) // zoom normal
	{
		f->zoom *= 0.9;
		f->shift_x += (x - WINSIZE_X / 2.0) * f->zoom / 1000;
		f->shift_y -= (y - WINSIZE_Y / 2.0) * f->zoom / 1000;
		return (1);
	}
	else if (key == MOUSE_WHEEL_CLICK) // reset zoom
	{
		f->zoom = 1.0;
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		return (1);
	}
	return (0);
}

// ne pas regenerer une julia
// generer burningship au cub ? tricron multi ?
void static	clicks_combo(int key, t_fractal *f)
{
	if (key == MOUSE_L && f->bind_combo == 1) // select julia cx cy
	{
		if (f->fractal_number < 4 || f->fractal_number == 7)
		{
			f->tmp_shift_x = f->shift_x;
			f->tmp_shift_y = f->shift_y;
			f->tmp_zoom = f->zoom;
			f->tmp_fractal_number = f->fractal_number;
			f->shift_x = 0.0;
			f->shift_y = 0.0;
			f->zoom = 1.0;
			if (f->fractal_number == 7)
				// on passe de multibrot a julia de multibrot
				f->fractal_number++;
			else if (f->fractal_number > 0 && f->fractal_number < 4)
				// on passe de mandel / burning / tricorn aux julias
				f->fractal_number += 3;
			printf("c = %f %fi\n", f->mouse_x, f->mouse_y);
		}
		f->j_x = f->mouse_x;
		f->j_y = f->mouse_y;
	}
}

void static	clicks(int key, int x, int y, t_fractal *f)
{
	if (key == MOUSE_R && f->bind_combo == 0) // zoom opti
	{
		f->zoom *= 1.2;
		f->shift_x -= (x - WINSIZE_X / 2.0) * f->zoom / 100;
		f->shift_y += (y - WINSIZE_Y / 2.0) * f->zoom / 100;
	}
	else if (key == MOUSE_L && f->bind_combo == 0) // zoom opti
	{
		f->zoom *= 0.8;
		f->shift_x += (x - WINSIZE_X / 2.0) * f->zoom / 100;
		f->shift_y -= (y - WINSIZE_Y / 2.0) * f->zoom / 100;
	}
	clicks_combo(key, f);
}

void	travel_between_fractals(t_fractal *f)
{
	f->j_x = f->o.x;
	f->j_y = f->o.y;
	while (f->t <= pi)
	{
		printf("boucle t = %f\nj_x = %f\nj_y = %f\n", f->t, f->j_x, f->j_y);
		mlx_clear_window(f->mlx, f->win);
		f->t += f->tc;
		f->j_x = f->o.x + ((sin(f->t) + 1) * 0.5) * f->d.x;
		f->j_y = f->o.y + ((sin(f->t) + 1) * 0.5) * f->d.y;
		/* if (f->psychedelic_colors == 1) */
		/* { */
		/* 	f->modify_color += 0.5; */
		/* } */
		printf("modify_color = %f\n", f->modify_color);
		iterate_on_pixels(f);
		mlx_do_sync(f->mlx);
		f->origin = 0;
	}
	f->t = 0;
}

/* void  */

int	mouse_inputs(int key, int x, int y, t_fractal *f)
{
	wheel(key, x, y, f);
	clicks(key, x, y, f);
	if (key == MOUSE_R && f->bind_combo == 1)
	{
		if (f->origin == 0)
		{
			f->o.x = f->mouse_x;
			f->o.y = f->mouse_y;
			printf("o.x = %f\n", f->o.x);
			printf("o.y = %f\n", f->o.y);
			f->origin = 1;
		}
		else
		{
			f->a.x = f->mouse_x;
			f->a.y = f->mouse_y;
			printf("a.x = %f\n", f->a.x);
			printf("a.y = %f\n", f->a.y);
			f->origin = 0;
			f->d.x = f->a.x - f->o.x;
			f->d.y = f->a.y - f->o.y;
			f->tmp_shift_x = f->shift_x;
			f->tmp_shift_y = f->shift_y;
			f->tmp_zoom = f->zoom;
			f->tmp_fractal_number = f->fractal_number;
			if (f->fractal_number <= 3)
				f->fractal_number = f->fractal_number + 3;
			/* if (f->fractal_number > 3 && f->fractal_number < 7)
				//on veut rester en julia si on est en julia */
			/* 	f->fractal_number = f->fractal_number; */
			else if (f->fractal_number == 7)
				f->fractal_number++;
			f->shift_x = 0.0;
			f->shift_y = 0.0;
			f->zoom = 1.0;
			travel_between_fractals(f);
		}
	}
	iterate_on_pixels(f);
	return (key);
}
