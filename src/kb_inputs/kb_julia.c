/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:03:36 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 17:18:31 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia_moves(int key, t_fractal *f)
{
	if (key == 65431)
		f->julia_constant.x += 1 * f->tmp.zoom / 1000;
	else if (key == 65433)
		f->julia_constant.x -= 1 * f->tmp.zoom / 1000;
	else if (key == 65430)
		f->julia_constant.y += 1 * f->tmp.zoom / 1000;
	else if (key == 65432)
		f->julia_constant.y -= 1 * f->tmp.zoom / 1000;
}

void	set_origin(t_fractal *f)
{
	f->o.x = f->julia_constant.x;
	f->o.y = f->julia_constant.y;
	f->flags.origin = 1;
}

void	set_arrival(t_fractal *f)
{
	f->a.x = f->julia_constant.x;
	f->a.y = f->julia_constant.y;
	f->flags.origin = 0;
	f->d.x = f->a.x - f->o.x;
	f->d.y = f->a.y - f->o.y;
	f->tmp.shift_x = f->shift_view.x;
	f->tmp.shift_y = f->shift_view.y;
	f->tmp.zoom = f->zoom;
	f->tmp.fractal_number = f->fractal_number;
	if (f->fractal_number <= 3)
		f->fractal_number = f->fractal_number + 3;
	else if (f->fractal_number == 7)
		f->fractal_number++;
	travel_between_fractals(f);
}

void	julia_constant_selector(int key, t_fractal *f)
{
	if (key == 97 && f->flags.bind_combo_shift == 1)
		f->flags.origin = 0;
	if (key == 97 && f->flags.bind_combo_shift == 0)
	{
		if (f->flags.origin == 0)
			set_origin(f);
		else
			set_arrival(f);
	}
}
