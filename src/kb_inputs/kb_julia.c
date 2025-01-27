

#include "../include/fractol.h"

void	julia_moves(int key, t_fractal *f)
{
	if (key == 65431) 
		f->j_x += 1 * f->tmp_zoom / 1000;
	else if (key == 65433) 
		f->j_x -= 1 * f->tmp_zoom / 1000;
	else if (key == 65430) 
		f->j_y += 1 * f->tmp_zoom / 1000;
	else if (key == 65432) 
		f->j_y -= 1 * f->tmp_zoom / 1000;
}

void	set_origin(t_fractal *f)
{
	f->o.x = f->j_x;
	f->o.y = f->j_y;
	f->origin = 1;
}

void	set_arrival(t_fractal *f)
{
	f->a.x = f->j_x;
	f->a.y = f->j_y;
	f->origin = 0;
	f->d.x = f->a.x - f->o.x;
	f->d.y = f->a.y - f->o.y;
	f->tmp_shift_x = f->shift_x;
	f->tmp_shift_y = f->shift_y;
	f->tmp_zoom = f->zoom;
	f->tmp_fractal_number = f->fractal_number;
	if (f->fractal_number <= 3)
		f->fractal_number = f->fractal_number + 3;
	else if (f->fractal_number == 7)
		f->fractal_number++;
	travel_between_fractals(f);
}

void	julia_constant_selector(int key, t_fractal *f)
{
	if (key == 97 && f->bind_combo_shift == 1)
		f->origin = 0;
	if (key == 97 && f->bind_combo_shift == 0)
	{
		if (f->origin == 0)
			set_origin(f);
		else
			set_arrival(f);
	}
}
