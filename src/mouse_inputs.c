//Header
//
//

#include <stdio.h>
/* #include <stdlib.h> */
#include "../include/fractol.h"

int	julia_dynamic(int x, int y, t_fractal *f)
{
	/* printf("x = %d | y = %d\n", x, y); */
	if (f->fractal_number == 6 || f->fractal_number == 5 || f->fractal_number == 4)
	{
		f->mouse_x = (scale(x, -3, +3, 0, WINSIZE_X) * f->tmp_zoom) + f->tmp_shift_x;
		f->mouse_y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->tmp_zoom) + f->tmp_shift_y;

	}
	else 
	{
		f->mouse_x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_x;
		f->mouse_y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->zoom) + f->shift_y;
	}
	return (0);
}

int wheel(int key, int x, int y, t_fractal *f)
{
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
		f->zoom = 1.0;
		f->shift_x = 0.0;
		f->shift_y = 0.0;
	}
	return (key);
}

int	mouse_inputs(int key, int x, int y, t_fractal *f)
{
	/* (void)x; //Zoom sous la souris ? */
	/* (void)y; */
	/* printf("key = %d | x = %d | y = %d\n", key, x, y); */
	/* if (wheel(key, x, y, *f)) */
	/*   return (key); */
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
	{ //les cdt de ces 3 ifs sont absurdes
		if (f->fractal_number == 1) //faire une structure tmp pour chaque fractale pour garder en memoire ou j'etais
		{
			f->tmp_shift_x = f->shift_x;
			f->tmp_shift_y = f->shift_y;
			f->tmp_zoom = f->zoom;
			f->tmp_fractal_number = f->fractal_number;
			f->shift_x = 0.0;
			f->shift_y = 0.0;
			f->zoom = 1.0;
			f->fractal_number = 4; //checker si julia de m = 4 !!
			printf("c = %f %fi\n", f->mouse_x, f->mouse_y); //voir le tip de david pour ca 
		}
		if (f->fractal_number == 2) //faire une structure tmp pour chaque fractale pour garder en memoire ou j'etais
		{
			f->tmp_shift_x = f->shift_x;
			f->tmp_shift_y = f->shift_y;
			f->tmp_zoom = f->zoom;
			f->tmp_fractal_number = f->fractal_number;
			f->shift_x = 0.0;
			f->shift_y = 0.0;
			f->zoom = 1.0;
			f->fractal_number = 5;
			printf("c = %f %fi\n", f->mouse_x, f->mouse_y); //voir le tip de david pour ca 
		}
		if (f->fractal_number == 3) //faire une structure tmp pour chaque fractale pour garder en memoire ou j'etais
		{
			f->tmp_shift_x = f->shift_x;
			f->tmp_shift_y = f->shift_y;
			f->tmp_zoom = f->zoom;
			f->tmp_fractal_number = f->fractal_number;
			f->shift_x = 0.0;
			f->shift_y = 0.0;
			f->zoom = 1.0;
			f->fractal_number = 6;
			printf("c = %f %fi\n", f->mouse_x, f->mouse_y); //voir le tip de david pour ca 
		}
		if (f->fractal_number == 7) //faire une structure tmp pour chaque fractale pour garder en memoire ou j'etais
		{
			f->tmp_shift_x = f->shift_x;
			f->tmp_shift_y = f->shift_y;
			f->tmp_zoom = f->zoom;
			f->tmp_fractal_number = f->fractal_number;
			f->shift_x = 0.0;
			f->shift_y = 0.0;
			f->zoom = 1.0;
			f->fractal_number = 8;
			printf("c = %f %fi\n", f->mouse_x, f->mouse_y); //voir le tip de david pour ca 
		}
		//backspace pour revenir d'une julia a l'origine
		f->j_x = f->mouse_x;
		f->j_y = f->mouse_y;
	}
	iterate_on_pixels(f);
	return (key);
}
