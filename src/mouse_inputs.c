/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:39:54 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/26 22:52:01 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/* #include <stdlib.h> */
#include "../include/fractol.h"
#include <math.h> // a virer

// Wheel pour moduler la vitesse de l'anim marche plus

// renommer
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

void	wheel_set_origin(t_fractal *f)
{
	f->o.x = f->mouse_x;
	f->o.y = f->mouse_y;
	f->origin = 1;
}

void	wheel_set_arrival(t_fractal *f)
{
	f->a.x = f->mouse_x;
	f->a.y = f->mouse_y;
	f->origin = 0;
	f->d.x = f->a.x - f->o.x;
	f->d.y = f->a.y - f->o.y;
	f->tmp_shift_x = f->shift_x;
	f->tmp_shift_y = f->shift_y;
	f->tmp_zoom = f->zoom;
	f->tmp_fractal_number = f->fractal_number;
	if (f->fractal_number <= 3)
		f->fractal_number = f->fractal_number + 3;
	else if (f->fractal_number == 7)
		f->fractal_number++;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1.0;
	travel_between_fractals(f);
}

void	dynamic_iterations(t_fractal *f)
{
	if ((f->bind_combo_shift == 0 && f->bind_combo_ctrl_l == 0
		&& f->bind_combo_alt_l == 0 && f->psychedelic_colors == 0) || f->psyche_switch == 1)
	{
		if (f->zooming_in == 1)
		{
			if (f->max_iterations < MAX_I)
				f->max_iterations += scale(f->max_iterations, 1.0, LDMIN, MIN_I,
						MAX_I) * f->speed_factor * 50 /*  0.5 */; //revoir la relation speed factor et it
			/* printf("max_iterations = %f\n", f->max_iterations); */
		}
		else if (f->zooming_out == 1)
		{
			if (f->max_iterations > MIN_I)
				f->max_iterations -= scale(f->max_iterations, 1.0, LDMIN, MIN_I,
						MAX_I) *  f->speed_factor * 50;
			/* 	printf("max_iterations = %f\n", f->max_iterations); */
		}
		/* double	zoom; */
		/**/
		/* zoom = f->zoom; */
		/* if (f->zooming_in == 1) */
		/* { */
		/* 	while (zoom * 10 < 10 && f->max_iterations < 250) */
		/* 	{ */
		/* 		f->max_iterations *= 1.005; */
		/* 		printf("iterupadte = %f\n", f->max_iterations); */
		/* 		zoom *= 10; */
		/* 	} */
		/* } */
		/* else if (f->zooming_out == 1) */
		/* { */
		/* 	while (zoom * 10 < 10 && f->max_iterations > 42) */
		/* 	{ */
		/* 		f->max_iterations *= 0.995; */
		/* 		printf("iterupadte = %f\n", f->max_iterations); */
		/* 		zoom *= 10; */
		/* 	} */
		/* } */
	}
}

//integrer dynamic iterations dans le zoom normal ?
void	wheel_zoom_out(int key, int x, int y, t_fractal *f)
{
	if (key == MOUSE_WHEEL_DOWN && f->bind_combo_ctrl_l == 0
		&& f->bind_combo_alt_l == 0 && f->bind_combo_shift == 0)
	{
		f->zoom *= 1.1;
		f->shift_x -= (x - WINSIZE_X / 2.0) * f->zoom / 1000;
		f->shift_y += (y - WINSIZE_Y / 2.0) * f->zoom / 1000;
	}
}

void	wheel_zoom_in(int key, int x, int y, t_fractal *f)
{
	double	relative_x;
	double	relative_y;

	if (key == MOUSE_WHEEL_UP && f->bind_combo_shift == 0
		&& f->bind_combo_ctrl_l == 0 && f->bind_combo_alt_l == 0) // zoom normal
	{
		f->zoom *= 0.9;
		relative_x = (x - WINSIZE_X / 2.0) * f->zoom / 1000;
		relative_y = (y - WINSIZE_Y / 2.0) * f->zoom / 1000;
		f->shift_x += relative_x;
		f->shift_y -= relative_y;
	}
}

void	wheel_zoom(int key, int x, int y, t_fractal *f)
{
	wheel_zoom_out(key, x, y, f);
	wheel_zoom_in(key, x, y, f);
}

void	wheel_combo(int key, t_fractal *f)
{
	if (key == MOUSE_WHEEL_UP)
	{
		if (f->bind_combo_shift == 1 
			&& f->bind_combo_ctrl_l == 0
			&& f->bind_combo_alt_l == 0
			&& f->max_iterations < MAX_I) // shift pour les iterations
			f->max_iterations++;
		else if (f->bind_combo_alt_l == 1 && f->bind_combo_ctrl_l == 0
			&& f->bind_combo_shift == 0 && f->speed_factor < 0.1)
			f->speed_factor *= 1.2; // du zoom
		else if (f->bind_combo_ctrl_l == 1 && f->bind_combo_alt_l == 0
			&& f->bind_combo_shift == 0
			&& f->tc < 1)
			f->tc *= 1.1;
	}
	else if (key == MOUSE_WHEEL_DOWN)
	{
		if (f->bind_combo_shift == 1 
			&& f->bind_combo_alt_l == 0
			&& f->bind_combo_ctrl_l == 0 // shift pour les iterations
			&& f->max_iterations > 10)
			f->max_iterations--;
		else if (f->bind_combo_alt_l == 1 && f->bind_combo_shift == 0
			&& f->bind_combo_ctrl_l == 0 && f->speed_factor > 0.001)
			f->speed_factor *= 0.8; // du zoom
		else if (f->bind_combo_ctrl_l == 1 && f->bind_combo_alt_l == 0
			&& f->bind_combo_shift == 0 && f->tc > 0.00001)
			f->tc *= 0.9;
	}
}

void	wheel(int key, int x, int y, t_fractal *f)
{
	// wheel vitesse zoom
	// wheel vitesse animation
	wheel_combo(key, f);
	wheel_zoom(key, x, y, f);
	if (key == MOUSE_WHEEL_CLICK && f->bind_combo_shift == 0 && f->bind_combo_ctrl_l == 0 && f->bind_combo_alt_l == 0) // reset zoom
	{
		f->zoom = 1.0;
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		f->zooming_in = 0;
		f->zooming_out = 0;
		f->max_iterations = MIN_I; // ca ne marche pas ?
	}
	else if (key == MOUSE_WHEEL_CLICK && f->bind_combo_shift == 1 && f->bind_combo_alt_l == 0 && f->bind_combo_ctrl_l == 0) // set travel
	{
		if (f->origin == 0)
			wheel_set_origin(f);
		else
			wheel_set_arrival(f);
	}
	else if (key == MOUSE_WHEEL_CLICK && f->bind_combo_shift == 0 && f->bind_combo_alt_l == 0 && f->bind_combo_ctrl_l == 1)// reset iterations
		f->max_iterations = MIN_I;
}

void	switch_palette(int key, t_fractal *f)
{
	if (key == MOUSE_L && f->bind_combo_alt_l == 1)
	{
		if (f->palette.n == 2)
			f->palette.n = 0;
		else if (f->palette.n < 2)
		{
			if (f->palette.n == 2)
				f->palette.n = 0;
			else
				f->palette.n++;
		}
	}
	else if (key == MOUSE_R && f->bind_combo_alt_l == 1)
	{
		if (f->palette.n == 0)
			f->palette.n = 2;
		else if (f->palette.n > 0)
		{
			if (f->palette.n == 0)
				f->palette.n = 2;
			else
				f->palette.n--;
		}
	}
}

// ne pas regenerer une julia
// generer burningship au cub ? tricron multi ?
void	clicks_combo(int key, t_fractal *f)
{
	if (key == MOUSE_L && f->bind_combo_shift == 1 && f->bind_combo_alt_l == 0
		&& f->bind_combo_ctrl_l == 0)
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
				f->fractal_number++;
			else if (f->fractal_number > 0 && f->fractal_number < 4)
				f->fractal_number += 3;
			printf("c = %Lf %Lfi\n", f->mouse_x, f->mouse_y);
		}
		f->j_x = f->mouse_x;
		f->j_y = f->mouse_y;
	}
	switch_palette(key, f);
}

void	clicks(int key, int x, int y, t_fractal *f)
{
	clicks_combo(key, f);
	if (key == MOUSE_R && f->bind_combo_shift == 0 && f->bind_combo_alt_l == 0
		&& f->bind_combo_ctrl_l == 0)
	{
		f->zoom *= 1.2;
		f->shift_x -= (x - WINSIZE_X / 2.0) * f->zoom / 100;
		f->shift_y += (y - WINSIZE_Y / 2.0) * f->zoom / 100;
	}
	else if (key == MOUSE_L && f->bind_combo_shift == 0
		&& f->bind_combo_alt_l == 0 && f->bind_combo_ctrl_l == 0) // alt l
	{
		f->zoom *= 0.8;
		f->shift_x += (x - WINSIZE_X / 2.0) * f->zoom / 100;
		f->shift_y -= (y - WINSIZE_Y / 2.0) * f->zoom / 100;
	}
}

// diviser ou virer les *= 0.99
// ou revoir le debug en entier
void	animated_zoom_out(int x, int y, t_fractal *f)
{
	f->zooming_out = 0;
	if (f->zoom < 1)
	{
		f->zooming_out = 1;
		f->zoom /= (1 - f->speed_factor);
		if (f->zoom > 0.1)
		{
			f->shift_x -= (x - WINSIZE_X / 2.0) * f->zoom / 1000;
			f->shift_y += (y - WINSIZE_Y / 2.0) * f->zoom / 1000;
			f->shift_x *= 0.99; // ralentir ou accélérer le recentrage
			f->shift_y *= 0.99;
			if (f->zoom > 0.9) // revoir ca
			{
				f->zoom = 1;
				f->shift_x = 0.0;
				f->shift_y = 0.0;
			}
		}
	}
	dynamic_iterations(f);
	iterate_on_pixels(f);
	mlx_do_sync(f->mlx.mlx);
}

void	animated_zoom_in(t_fractal *f)
{
	f->zooming_in = 0;
	if (f->zoom > f->zoom * 0.5)
	{
		f->zooming_in = 1;
		f->zoom *= (1 - f->speed_factor);
		dynamic_iterations(f);
		iterate_on_pixels(f);
		mlx_do_sync(f->mlx.mlx);
	}
}

void	animated_zoom(int key, int x, int y, t_fractal *f)
{
	if (key == MOUSE_R && f->bind_combo_alt_l == 0 && f->bind_combo_ctrl_l == 1
		&& f->bind_combo_shift == 0)
	{
		if (f->zooming_out == 0)
		{
			f->max_iterations_start = f->max_iterations;
			f->zooming_out_start = f->zoom;
			f->zooming_in = 0;
			f->zooming_out_x = x;
			f->zooming_out_y = y;
			animated_zoom_out(x, y, f);
		}
		else
			f->zooming_out = 0;
	}
	else if (key == MOUSE_L && f->bind_combo_ctrl_l == 1
		&& f->bind_combo_alt_l == 0 && f->bind_combo_shift == 0)
	{
		if (f->zooming_in == 0)
		{
			f->zooming_out = 0;
			animated_zoom_in(f);
		}
		else
			f->zooming_in = 0;
	}
}

// a redeclarer correctement et a renommer
int	travel_update(void *param)
{
	t_fractal *f = (t_fractal *)param; // revoir ca
	if (f->traveling == 1)
		travel_between_fractals(f);
	if (f->zooming_out == 1)
		animated_zoom_out(f->zooming_out_x, f->zooming_out_y, f);
	if (f->zooming_in == 1)
		animated_zoom_in(f);
	return (0);
}

void	travel_between_fractals(t_fractal *f)
{
	/* double iterations_psyche; */

	f->traveling = 1;
	f->t += f->tc;
	f->j_x = f->o.x + ((sin(f->t) + 1) * 0.5) * f->d.x;
	f->j_y = f->o.y + ((sin(f->t) + 1) * 0.5) * f->d.y;
	/* if (f->psyche_switch == 1 && f->psychedelic_colors == 1)  */
	/* { */
	/* 	iterations_psyche = (sin(f->t) + 1) * 0.5 + 1; */
	/* 	f->max_iterations += iterations_psyche * 1.1; */
	/* 	iterate_on_pixels(f); */
	/* 	f->max_iterations -= iterations_psyche * 1.1; */
	/* } */
	iterate_on_pixels(f);
	mlx_do_sync(f->mlx.mlx);
}

/* void  */

int	mouse_inputs(int key, int x, int y, t_fractal *f)
{
	/* printf("key = %d\n", key); */
	wheel(key, x, y, f);
	clicks(key, x, y, f);
	animated_zoom(key, x, y, f);
	iterate_on_pixels(f);
	return (key);
}
