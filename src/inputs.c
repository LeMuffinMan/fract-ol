// HEADER
//
//
/* switch color */
/* switch renderer ? */
/* 	julia from mandel */
/* rendre zoom moins laggy */
#include "../include/fractol.h"
#include <stdio.h> //remplacer par ft_printf

int	julia_dynamic(int x, int y, t_fractal *f)
{
	/* printf("x = %d | y = %d\n", x, y); */
	f->mouse_x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_x;
	f->mouse_y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->zoom) + f->shift_y;
	return (0);
}

int	mouse_inputs(int key, int x, int y, t_fractal *f)
{
	/* (void)x; //Zoom sous la souris ? */
	/* (void)y; */
	/* printf("key = %d | x = %d | y = %d\n", key, x, y); */
	if (key == MOUSE_WHEEL_DOWN) //zoom normal
	{
		f->zoom *= 1.1;
		f->shift_x -= (x - WINSIZE_X / 2.0) * f->zoom / 1000;
		f->shift_y += (y - WINSIZE_Y / 2.0) * f->zoom / 1000;
	}
	else if (key == MOUSE_WHEEL_UP) //zoom normal
	{
		f->zoom *= 0.9;
		f->shift_x += (x - WINSIZE_X / 2.0) * f->zoom / 1000;
		f->shift_y -= (y - WINSIZE_Y / 2.0) * f->zoom / 1000;
	}
	else if (key == MOUSE_WHEEL_CLICK) //reset zoom
	{
		f->max_iterations = 50;
		f->zoom = 1.0;
		f->shift_x = 0.0;
		f->shift_y = 0.0;
	}
	else if (key == MOUSE_R) //zoom opti
	{
		f->zoom *= 1.2;
		f->shift_x -= (x - WINSIZE_X / 2.0) * f->zoom / 100;
		f->shift_y += (y - WINSIZE_Y / 2.0) * f->zoom / 100;
	}
	else if (key == MOUSE_L && f->bind_combo == 0) //zoom opti
	{
		f->zoom *= 0.8;
		f->shift_x += (x - WINSIZE_X / 2.0) * f->zoom / 100;
		f->shift_y -= (y - WINSIZE_Y / 2.0) * f->zoom / 100;
	}
	else if (key == MOUSE_L && f->bind_combo == 1) //select julia cx cy
	{
		if (f->fractal_number != 2) //revoir le switch back et un tmp pour garder le zoom de mandelbrot
		{
			f->tmp_shift_x = f->shift_x;
			f->tmp_shift_y = f->shift_y;
			f->tmp_zoom = f->zoom;
			f->shift_x = 0.0;
			f->shift_y = 0.0;
			f->zoom = 1.0;
			f->fractal_number = 2;
			printf("c = %f %fi\n", f->mouse_x, f->mouse_y);
		}
		f->j_x = f->mouse_x;
		f->j_y = f->mouse_y;
	}
	iterate_on_pixels(f);
	return (key);
}

int	kb_inputs(int key, t_fractal *f)
{
	printf("key = %d\n", key);
	if (key == WIN_X || key == ESC)
		quit(f);
	else if (key == SHIFT)
	{
		if (f->bind_combo == 0)
			f->bind_combo = 1;
		else
			f->bind_combo = 0;
	}
	else if (key == RIGHT)
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
	else if (key == PLUS && f->bind_combo == 1)
		f->modify_color += 1, printf("color modify : %d\n", f->modify_color);
	else if (key == PLUS && f->bind_combo == 0)
	{
		f->switch_iterations += 1;
		printf("iterations switch = %d\n", f->switch_iterations); // A VIRER !!!
		return (0);
	}
	else if (key == MINUS && f->bind_combo == 1)
		f->modify_color -= 1;
	else if (key == MINUS && f->switch_iterations > 1 && f->bind_combo == 0)
	{
		f->switch_iterations -= 1;
		printf("iterations switch = %d\n", f->switch_iterations);
		return (0);
	}
	else if (key == NUM_ENTER)
	{
		if (f->bind_combo == 1)
		{
			f->max_iterations = 50;
			f->switch_iterations = 50; //a virer du coup ?
			printf("max_iterations reset at 50\n");
		}
		else
		{
			f->max_iterations = f->switch_iterations; // revoir le nom
			printf("max_iterations = %d\n", f->max_iterations);
		}
	}
	else if (key == 49 && f->fractal_number != 1)
	{
		f->shift_x = f->tmp_shift_x;
		f->shift_y = f->tmp_shift_y;
		f->zoom = f->tmp_zoom;
		f->fractal_number = 1;
	}
	else if (key == 50 && f->fractal_number != 2)
	{
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		f->zoom = 1.0;
		f->fractal_number = 2;
	}
	else if (key == 51 && f->fractal_number != 3)
	{
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		f->zoom = 1.0;
		f->fractal_number = 3;
	}
	else if (key == 52 && f->fractal_number != 4)
	{
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		f->zoom = 1.0;
		f->fractal_number = 4;
	}
	/* printf("SHIFT : %d\nshift_x = %f\nshift_y = %f\nzoom = %f\n", f->bind_combo, */
		/* f->shift_x, f->shift_y, f->zoom); */
	iterate_on_pixels(f);
	return (0);
}

int	shift_toggle(int key, t_fractal *f)
{
	if (key == SHIFT)
		f->bind_combo = 0;
	return (0);
}
