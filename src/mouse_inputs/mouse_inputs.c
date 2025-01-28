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

#include <stdio.h> //remplacer par printf !
#include "../include/fractol.h"

void	wheel(int key, int x, int y, t_fractal *f)
{
	wheel_combo(key, f);
	wheel_zoom(key, x, y, f);
	if (key == MOUSE_WHEEL_CLICK && f->bind_combo_shift == 0 && f->bind_combo_ctrl_l == 0 && f->bind_combo_alt_l == 0) // reset zoom
	{
		f->zoom = 1.0;
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		f->zooming_in = 0;
		f->zooming_out = 0;
		f->max_iterations = MIN_I; 
	}
	else if (key == MOUSE_WHEEL_CLICK && f->bind_combo_shift == 1 && f->bind_combo_alt_l == 0 && f->bind_combo_ctrl_l == 0) // set travel
	{


		if (f->origin == 0)
			wheel_set_origin(f);
		else
			wheel_set_arrival(f);
	}
	else if (key == MOUSE_WHEEL_CLICK && f->bind_combo_shift == 0 && f->bind_combo_alt_l == 0 && f->bind_combo_ctrl_l == 1) // reset iterations
		f->max_iterations = MIN_I;
}

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
		&& f->bind_combo_alt_l == 0 && f->bind_combo_ctrl_l == 0) 
	{
		f->zoom *= 0.8;
		f->shift_x += (x - WINSIZE_X / 2.0) * f->zoom / 100;
		f->shift_y -= (y - WINSIZE_Y / 2.0) * f->zoom / 100;
	}
}


int	mouse_inputs(int key, int x, int y, t_fractal *f)
{
	#include <stdio.h>
	printf("tc = %f\n", f->tc);
	wheel(key, x, y, f);
	clicks(key, x, y, f);
	animated_zoom(key, x, y, f);
	iterate_on_pixels(f);
	return (key);
}
