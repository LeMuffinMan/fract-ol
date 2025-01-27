

#include "../include/fractol.h"

void color_switch_R(t_fractal *f)
{
		if (f->psychedelic_colors == 1)
			f->palette.n = 0;
		else
		{
			if (f->red_toggle == 0)
				f->red_toggle = 1;
			else
				f->red_toggle = 0;
		}
	}
void color_switch_B(t_fractal *f)
{
		if (f->psychedelic_colors == 1)
			f->palette.n = 2;
		else
		{
			if (f->green_toggle == 0)
				f->green_toggle = 1;
			else
				f->green_toggle = 0;
		}
	}
void color_switch_G(t_fractal *f)
{
		if (f->psychedelic_colors == 1)
			f->palette.n = 1;
		else
		{
			if (f->blue_toggle == 0)
				f->blue_toggle = 1;
			else
				f->blue_toggle = 0;
		}
	}

void	color_shift(int key, t_fractal *f)
{
	if (key == R)
		color_switch_R(f);
	else if (key == B)
		color_switch_B(f);
	else if (key == G)
		color_switch_G(f);
	else if (key == E) 
	{
		if (f->psychedelic_colors == 0)
			f->psychedelic_colors = 1;
		else
			f->psychedelic_colors = 0;
	}
}
