
#include "../include/fractol.h"

void switch_next_palette(t_fractal *f)
{
		if (f->palette.n == 2)
			f->palette.n = 0;
		else if (f->palette.n < 2)
		{
			if (f->palette.n == 2)
				f->palette.n = 0;
			else
				f->palette.n++;
		}

}
void switch_prev_palette(t_fractal *f)
{
		if (f->palette.n == 0)
			f->palette.n = 2;
		else if (f->palette.n > 0)
		{
			if (f->palette.n == 0)
				f->palette.n = 2;
			else
				f->palette.n--;
		}
}

void	switch_palette(int key, t_fractal *f)
{
	if (key == MOUSE_L && f->bind_combo_alt_l == 1)
		switch_prev_palette(f);
	else if (key == MOUSE_R && f->bind_combo_alt_l == 1)
		switch_next_palette(f);
}
