

#include "../include/fractol.h"

void	wheel_zoom_out(int key, int x, int y, t_fractal *f)
{
	if (key == MOUSE_WHEEL_DOWN && f->bind_combo_ctrl_l == 0
		&& f->bind_combo_alt_l == 0 && f->bind_combo_shift == 0)
	{
		f->zoom *= 1.1;
		f->shift_x -= (x - WINSIZE_X / 2.0) * f->zoom / 1000;
		f->shift_y += (y - WINSIZE_Y / 2.0) * f->zoom / 1000;
	}
}

void	wheel_zoom_in(int key, int x, int y, t_fractal *f)
{
	double	relative_x;
	double	relative_y;

	if (key == MOUSE_WHEEL_UP && f->bind_combo_shift == 0
		&& f->bind_combo_ctrl_l == 0 && f->bind_combo_alt_l == 0) // zoom normal
	{
		f->zoom *= 0.9;
		relative_x = (x - WINSIZE_X / 2.0) * f->zoom / 1000;
		relative_y = (y - WINSIZE_Y / 2.0) * f->zoom / 1000;
		f->shift_x += relative_x;
		f->shift_y -= relative_y;
	}
}

void	wheel_zoom(int key, int x, int y, t_fractal *f)
{
	wheel_zoom_out(key, x, y, f);
	wheel_zoom_in(key, x, y, f);
}

