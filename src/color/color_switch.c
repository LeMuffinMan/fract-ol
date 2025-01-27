
#include "../include/fractol.h"

void switch_red(t_fractal *f)
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
void switch_green(t_fractal *f)
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
void switch_blue(t_fractal *f)
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

void	color_shift(int key, t_fractal *f) 
{
	if (key == R)
		switch_red(f);
	else if (key == B)
		switch_blue(f);
	else if (key == G)
			switch_green(f);
	else if (key == E) 
	{
		if (f->psychedelic_colors == 0)
			f->psychedelic_colors = 1;
		else
			f->psychedelic_colors = 0;
	}
}

