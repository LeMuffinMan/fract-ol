
#include "../include/fractol.h"

void	space_pause(int key, t_fractal *f)
{
	if (key == SPACE) 
	{
		if (f->traveling == 1)
			f->traveling = 0;
		else
			f->traveling = 1;
	}
}

void	animation_speed_keys(int key, t_fractal *f)
{
	if (key == PLUS && f->bind_combo_ctrl_l == 1)
		f->tc *= 2;
	if (key == MINUS && f->bind_combo_ctrl_l == 1)
		f->tc /= 2;
}
