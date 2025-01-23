/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:53:43 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/23 17:53:45 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* switch color */
/* switch renderer ? */
/* 	julia from mandel */
/* rendre zoom moins laggy */
#include "../include/fractol.h"
#include <stdio.h> //remplacer par ft_printf

int arrows(int key, t_fractal *f)
{
	if (key == RIGHT)
		f->shift_x += (0.2 * f->zoom);
	else if (key == LEFT)
		f->shift_x -= (0.2 * f->zoom);
	else if (key == DOWN)
	{
		if (f->bind_combo == 1)
			f->zoom *= 0.7;
		else
			f->shift_y -= (0.2 * f->zoom);
	}
	else if (key == UP)
	{
		if (f->bind_combo == 1)
			f->zoom *= 1.3;
		else
			f->shift_y += (0.2 * f->zoom);
	}
	return (key);
}

int pav_num_enter(int key, t_fractal *f)
{
	if (key == NUM_ENTER)
	{
		if (f->bind_combo == 1)
		{
			f->max_iterations = 100;
			f->switch_iterations = 100; //a virer du coup ?
		}
		else
			f->max_iterations = f->switch_iterations; // revoir le nom
		printf("max_iterations = %d\n", f->max_iterations);
	}
	return (key);
}

int pav_num_operators(int key, t_fractal *f)
{
	if (key == PLUS && f->bind_combo == 1)
	{
		f->modify_color += 1;
		printf("color modify : %d\n", f->modify_color);
	}
	else if (key == PLUS && f->bind_combo == 0)
	{
		f->switch_iterations += 1;
		printf("iterations switch = %d\n", f->switch_iterations); // A VIRER !!!
	}
	else if (key == MINUS && f->bind_combo == 1)
		f->modify_color -= 1;
	else if (key == MINUS && f->switch_iterations > 1 && f->bind_combo == 0)
	{
		f->switch_iterations -= 1;
		printf("iterations switch = %d\n", f->switch_iterations);
	}
	return (key);
}

//ajouter un racourci pour chaque variante de julia
void num_fractal_switch(int key, t_fractal *f)
{
	if (key >= 49 && key <= 53)
	{
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		f->zoom = 1.0;
		f->fractal_number = 1;
		if (f->fractal_number != 1) //on voudrait reset les power quand on appuie sur 1/!
			f->power = 2;
		if (f->fractal_number != key - '0')
			f->fractal_number = key - '0';
	}
}

void color_shift(int key, t_fractal *f)
{
	if (key == R)
	{
		f->modify_color = 0;
		f->palette_n = 3;
	}
	else if (key == G)
	{
		f->modify_color = 0;
		f->palette_n = 2;
	}
	else if (key == B)
	{	
		f->modify_color = 0;
		f->palette_n = 1;
	}
	else if (key == E) //E
	{
		if (f->psychedelic_colors == 0)
			f->psychedelic_colors = 1;
		else 
			f->psychedelic_colors = 0;
	}
}

void multibrot_power_switch(int key, t_fractal *f)
{
	if (key == 61 && (f->fractal_number == 1 || f->fractal_number == 7))
	{
		f->power++;
		printf("multibrot power %f\n", f->power);
		f->fractal_number = 7;
	}
	else if (key == 45 && f->fractal_number == 7)
	{
		if (f->power == 3) // pour deux on revient sur un mandelbrot normal ?
			f->fractal_number = 1;
		else 
			f->fractal_number = 7;
		f->power--;
		printf("multibrot power %f\n", f->power);
	}
}

void backspace_switch(int key, t_fractal *f) // marche pas !
{
	if (key == BACKSPACE)
	{
		double tmp;
		tmp = f->fractal_number;
		f->fractal_number = f->tmp_fractal_number;
		f->tmp_fractal_number = tmp;
		tmp = f->shift_x;
		f->shift_x = f->tmp_shift_x;
		f->tmp_shift_x = tmp;
		tmp = f->shift_y;
		f->shift_y = f->tmp_shift_y;
		f->tmp_shift_y = tmp;
		tmp = f->zoom;
		f->zoom = f->tmp_zoom;
		f->tmp_zoom = tmp;
	}

}
//conserver le zoom et le shift de chaque fractale quand on switch
int	kb_inputs(int key, t_fractal *f)
{
	/* printf("key = %d\n", key); */
	if (key == WIN_X || key == ESC)
		quit(f);
	arrows(key, f);
	pav_num_operators(key, f);
	if (key == SHIFT)
	{
		if (f->bind_combo == 0)
			f->bind_combo = 1;
		else
			f->bind_combo = 0;
	}
	num_fractal_switch(key, f);
	color_shift(key, f);
	multibrot_power_switch(key, f);
	backspace_switch(key, f);
	iterate_on_pixels(f);
	return (0);
}

//on key release
int	shift_toggle(int key, t_fractal *f)
{
	if (key == SHIFT)
		f->bind_combo = 0;
	return (0);
}
