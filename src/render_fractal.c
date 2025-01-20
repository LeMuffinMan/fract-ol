//header
//
//
//

 /*  racourcir set_complexes */
 /* reorganiser si 6 fonctions ?  */

#include "../include/fractol.h"
#include <math.h>

double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max) //a reec.xire
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

void set_complexes(int x, int y, t_fractal *f) //racrourci avec un set julia custom
{			
	f->z.x = 0.0;
	f->z.y = 0.0;
	if (f->fractal_number == 1)
	{
		f->c.x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_x;
		f->c.y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->zoom) + f->shift_y;
	}
	else if (f->fractal_number == 3)
	{
		f->c.x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_x;
		f->c.y = (scale(y, -3, +3, 0, WINSIZE_Y) * f->zoom) - f->shift_y;
	}
	else if (f->fractal_number == 4)
	{
		f->z.x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_x;
		f->z.y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->zoom) + f->shift_y;

		f->c.x = f->z.x;
		f->c.y = f->z.y;
	}
	else if (f->fractal_number == 2)
	{
		f->z.x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_x;
		f->z.y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->zoom) + f->shift_y;

		f->c.x = f->j_x; //-0.8;
		f->c.y = f->j_y; //0.156;
	}
}

void 	iterate_on_pixels(t_fractal *f)
{
	int x;
	int y;

	y = 0;
	while (y < WINSIZE_Y)
	{
		x = 0;
		while (x < WINSIZE_X)
		{
			set_complexes(x, y, f);
			render_fractal(x, y, f);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_p, 0, 0);
}


void calculate_f(t_fractal *f)
{
	double tmp;

	if (f->fractal_number == 1 || f->fractal_number == 2)
		f->z = sum_complex(square_complex(f->z), f->c);
	if (f->fractal_number == 3)
	{
		f->z.x = fabs(f->z.x);
		f->z.y = fabs(f->z.y);
		tmp = 2 * f->z.x * f->z.y + f->c.y;
		f->z.x = f->z.x * f->z.x - f->z.y * f->z.y + f->c.x;
		f->z.y = tmp;
	}
	if (f->fractal_number == 4)
	{
		tmp = -2 * f->z.x * f->z.y + f->c.y;
		f->z.x = f->z.x * f->z.x - f->z.y * f->z.y + f->c.x;
		f->z.y = tmp;
	}
}

void	render_fractal(int x, int y, t_fractal *f)
{
	int			i;
	int			color;

	i = 0;
	while (i < f->max_iterations)
	{
		calculate_f(f);
		if ((f->z.x * f->z.x) + (f->z.y * f->z.y) > f->escape_value)
		{
	  	f->mu = log(log(norm_complex(f->z))) / log(2);
		  color = generate_smooth_color(i, f->mu, f->max_iterations);
			colorize_pixel(x, y, &f->img, color);
			return ;
		}
		i++;
	}
	colorize_pixel(x, y, &f->img, BLACK);
}
