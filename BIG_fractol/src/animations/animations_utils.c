/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:33:54 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 16:23:54 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	get_mouse_coords(int x, int y, t_fractal *f)
{
	if (f->fractal_number == 6 || f->fractal_number == 5
		|| f->fractal_number == 4)
	{
		f->mouse.x = (scale(x, -3, +3, 0, WINSIZE_X) * f->tmp.zoom)
			+ f->tmp.shift_x;;
		f->mouse.y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->tmp.zoom)
			+ f->tmp.shift_y;;
	}
	else
	{
		f->mouse.x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_view.x;
		f->mouse.y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->zoom) + f->shift_view.y;
	}
	return (0);
}

void	wheel_set_origin(t_fractal *f)
{
	f->o.x = f->mouse.x;
	f->o.y = f->mouse.y;
	f->flags.origin = 1;
}

void	wheel_set_arrival(t_fractal *f)
{
	f->a.x = f->mouse.x;
	f->a.y = f->mouse.y;
	f->flags.origin = 0;
	f->d.x = f->a.x - f->o.x;
	f->d.y = f->a.y - f->o.y;
	f->tmp.shift_x = f->shift_view.x;
	f->tmp.shift_y = f->shift_view.y;
	f->tmp.zoom = f->zoom;
	f->tmp.fractal_number = f->fractal_number;
	if (f->fractal_number <= 3)
		f->fractal_number = f->fractal_number + 3;
	else if (f->fractal_number == 7)
		f->fractal_number++;
	f->shift_view.x = 0.0;
	f->shift_view.y = 0.0;
	f->zoom = 1.0;
	travel_between_fractals(f);
}

void	dynamic_iterations(t_fractal *f)
{
	if ((f->flags.bind_combo_shift == 0 && f->flags.bind_combo_ctrl_l == 0
			&& f->flags.bind_combo_alt_l == 0 && f->flags.psychedelic_colors == 0)
		|| f->flags.psyche_switch == 1)
	{
		if (f->flags.zooming_in == 1)
		{
			if (f->max_iterations < MAX_I)
				f->max_iterations += scale(f->max_iterations, 1.0, LDMIN, MIN_I,
						MAX_I) * f->speed_factor * 50;
		}
		else if (f->flags.zooming_out == 1)
		{
			if (f->max_iterations > MIN_I)
				f->max_iterations -= scale(f->max_iterations, 1.0, LDMIN, MIN_I,
						MAX_I) * f->speed_factor * 50;
		}
	}
}

void	set_animated_zoom_out(int x, int y, t_fractal *f)
{
	if (f->flags.zooming_out == 0)
	{
		f->max_iterations_start = f->max_iterations;
		f->zooming_out_start = f->zoom;
		f->flags.zooming_in = 0;
		f->zooming_out_coords.x = x;
		f->zooming_out_coords.y = y;
		animated_zoom_out(x, y, f);
	}
	else
		f->flags.zooming_out = 0;
}
