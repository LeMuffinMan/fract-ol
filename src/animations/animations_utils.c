
#include "../include/fractol.h"

// renommer
int	julia_dynamic(int x, int y, t_fractal *f)
{
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
	#include <stdio.h>
	printf("tc = %f\n", f->tc);
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
						MAX_I) * f->speed_factor * 50; 
		}
		else if (f->zooming_out == 1)
		{
			if (f->max_iterations > MIN_I)
				f->max_iterations -= scale(f->max_iterations, 1.0, LDMIN, MIN_I,
						MAX_I) *  f->speed_factor * 50;
		}
	}
}

void set_animated_zoom_out(int x, int y, t_fractal *f)
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
