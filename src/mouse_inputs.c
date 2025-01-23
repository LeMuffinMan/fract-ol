// Header
//
//

#include <stdio.h>
/* #include <stdlib.h> */
#include "../include/fractol.h"

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

int	wheel(int key, int x, int y, t_fractal *f)
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

void	clicks_combo(int key, t_fractal *f)
{
	if (key == MOUSE_L && f->bind_combo == 1) // select julia cx cy
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
		printf("c = %f %fi\n", f->mouse_x, f->mouse_y);
		f->j_x = f->mouse_x;
		f->j_y = f->mouse_y;
	}
}

void	clicks(int key, int x, int y, t_fractal *f)
{
	if (key == MOUSE_R) // zoom opti
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

int	mouse_inputs(int key, int x, int y, t_fractal *f)
{
	wheel(key, x, y, f);
	clicks(key, x, y, f);
	iterate_on_pixels(f);
	return (key);
}
