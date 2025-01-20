//HEADER
//
//
 	/* switch color */
 	/* switch renderer ? */
 	/* 	julia from mandel */
 	/* rendre zoom moins laggy */
#include "../include/fractol.h"
#include <stdio.h> //remplacer par ft_printf

int julia_dynamic(int x, int y, t_fractal *f)
{
	/* printf("x = %d | y = %d\n", x, y); */
	f->mouse_x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_x;
	f->mouse_y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->zoom) + f->shift_y;
	return (0);
}

int	mouse_inputs(int key, int x, int y, t_fractal *f)
{
	(void)x; //Zoom sous la souris ?
	(void)y;
	/* printf("key = %d | x = %d | y = %d\n", key, x, y); */
	if (key == MOUSE_WHEEL_DOWN)
	{
		f->max_iterations = 50;
		f->zoom *= 1.1;
	}
	else if (key == MOUSE_WHEEL_UP)
	{
		f->max_iterations = 50;
		f->zoom *= 0.9;
	}
	else if (key == MOUSE_WHEEL_CLICK)
	{
		f->zoom = 1.0;
		f->shift_x = 0.0;
		f->shift_y = 0.0;
	}
	else if (key == 1) //click a define
	{
		f->j_x = f->mouse_x;
		f->j_y = f->mouse_y;
	}
	iterate_on_pixels(f);
	return (key);
}

int kb_inputs(int key, t_fractal *f)
{
	/* printf("key = %d\n", key); */
	if (key == WIN_X || key == ESC)
		quit(f);
	else if (key == RIGHT)
		f->shift_x += (0.2 * f->zoom);
	else if (key == LEFT)
		f->shift_x -= (0.2 * f->zoom);
	else if (key == DOWN)
		f->shift_y -= (0.2 * f->zoom);
	else if (key == UP)
		f->shift_y += (0.2 * f->zoom);
	else if (key == PLUS)
	{
		f->select_iterations += 1;
		printf("select_iterations = %d\n", f->select_iterations); //A VIRER !!!
		return (0);
	}
	else if (key == MINUS && f->max_iterations > 1)
	{
		f->select_iterations -= 1;
		printf("select_iterations = %d\n", f->select_iterations);
		return (0);
	}
	else if (key == NUM_ENTER)
	{
		f->max_iterations = f->select_iterations; //revoir le nom
		printf("max_iterations = %d\n", f->max_iterations);
	}
	iterate_on_pixels(f);
	return (0);
}
