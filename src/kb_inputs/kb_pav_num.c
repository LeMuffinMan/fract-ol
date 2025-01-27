

#include "../include/fractol.h"

int	pav_num_enter(int key, t_fractal *f)
{
	if (key == NUM_ENTER)
	{
		if (f->bind_combo_shift == 1)
		{
			f->max_iterations = MIN_I;
			f->switch_iterations = MIN_I;
		}
		else
			f->max_iterations = f->switch_iterations;
	}
	return (key);
}

int	pav_num_operators(int key, t_fractal *f)
{
	if (key == PLUS && f->bind_combo_shift == 0 && f->bind_combo_ctrl_l == 0)
		f->switch_iterations += 1;
	else if (key == MINUS && f->switch_iterations > 1
		&& f->bind_combo_shift == 0 && f->bind_combo_ctrl_l == 0)
		f->switch_iterations -= 1;
	pav_num_enter(key, f);
	return (key);
}
