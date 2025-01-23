// HEADER
//
//
/* switch color */
/* switch renderer ? */
/* 	julia from mandel */
/* rendre zoom moins laggy */
#include "../include/fractol.h"
#include <stdio.h> //remplacer par ft_printf

//conserver le zoom et le shift de chaque fractale quand on switch
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
			f->max_iterations = 100;
			f->switch_iterations = 100; //a virer du coup ?
			printf("max_iterations reset at 50\n");
		}
		else
		{
			f->max_iterations = f->switch_iterations; // revoir le nom
			printf("max_iterations = %d\n", f->max_iterations);
		}
	}
	//1/!
	else if (key == 49 && f->fractal_number != 1) // A DEFINE !!
	{
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		f->zoom = 1.0;
		f->fractal_number = 1;
		f->power = 2;
	}
	//2/@
	else if (key == 50 && f->fractal_number != 2)
	{
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		f->zoom = 1.0;
		f->fractal_number = 2;
	}
	//3/#
	else if (key == 51 && f->fractal_number != 3)
	{
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		f->zoom = 1.0;
		f->fractal_number = 3;
	}
	//4/$
	else if (key == 52 && f->fractal_number != 4)
	{
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		f->zoom = 1.0;
		f->fractal_number = 4;
	}
	else if (key == 53 && f->fractal_number != 9)
	{
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		f->zoom = 1.0;
		f->fractal_number = 9;
	}
	else if (key == R)
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
	else if (key == 61 && (f->fractal_number == 1 || f->fractal_number == 7))
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
	else if (key == BACKSPACE)
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
