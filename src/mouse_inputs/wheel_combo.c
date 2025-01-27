

#include "../include/fractol.h"

void	wheel_combo_up(t_fractal *f)
{
		if (f->bind_combo_shift == 1 
			&& f->bind_combo_ctrl_l == 0
			&& f->bind_combo_alt_l == 0
			&& f->max_iterations < MAX_I) // shift pour les iterations
			f->max_iterations++;
		else if (f->bind_combo_alt_l == 1 && f->bind_combo_ctrl_l == 0
			&& f->bind_combo_shift == 0 && f->speed_factor < 0.1)
			f->speed_factor *= 1.2; // du zoom
		else if (f->bind_combo_ctrl_l == 1 && f->bind_combo_alt_l == 0
			&& f->bind_combo_shift == 0
			&& f->tc < 1)
			f->tc *= 1.1;

}

void	wheel_combo_down(t_fractal *f)
{
		if (f->bind_combo_shift == 1 
			&& f->bind_combo_alt_l == 0
			&& f->bind_combo_ctrl_l == 0 // shift pour les iterations
			&& f->max_iterations > 10)
			f->max_iterations--;
		else if (f->bind_combo_alt_l == 1 && f->bind_combo_shift == 0
			&& f->bind_combo_ctrl_l == 0 && f->speed_factor > 0.001)
			f->speed_factor *= 0.8; // du zoom
		else if (f->bind_combo_ctrl_l == 1 && f->bind_combo_alt_l == 0
			&& f->bind_combo_shift == 0 && f->tc > 0.00001)
			f->tc *= 0.9;
}

void	wheel_combo(int key, t_fractal *f)
{
	if (key == MOUSE_WHEEL_UP)
		wheel_combo_up(f);
	else if (key == MOUSE_WHEEL_DOWN)
			wheel_combo_down(f);
}

