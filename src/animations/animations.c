
#include "../include/fractol.h"
#include <math.h>

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
			f->shift_x *= 0.99; 
			f->shift_y *= 0.99;
			if (f->zoom > 0.9)
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
			set_animated_zoom_out(x, y, f);
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
	{
		travel_between_fractals(f);
	#include <stdio.h>
	printf("tc = %f\n", f->tc);
	}
	if (f->zooming_out == 1)
		animated_zoom_out(f->zooming_out_x, f->zooming_out_y, f);
	if (f->zooming_in == 1)
		animated_zoom_in(f);
	return (0);
}

void	travel_between_fractals(t_fractal *f)
{


	f->traveling = 1;
	f->t += f->tc;
	f->j_x = f->o.x + ((sin(f->t) + 1) * 0.5) * f->d.x;
	f->j_y = f->o.y + ((sin(f->t) + 1) * 0.5) * f->d.y;
	iterate_on_pixels(f);
	mlx_do_sync(f->mlx.mlx);
}

