/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:04:13 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 14:05:14 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	debug_switch(int key, t_fractal *f)
{
	if (key == D)
	{
		if (f->debug == 0)
			f->debug = 1;
		else if (f->debug == 1)
			f->debug = 0;
	}
}

void	psyche_switch(int key, t_fractal *f)
{
	if (key == P)
	{
		if (f->psyche_switch == 0)
			f->psyche_switch = 1;
		else
			f->psyche_switch = 0;
	}
}

void	num_fractal_switch(int key, t_fractal *f)
{
	if (key >= 49 && key <= 55)
	{
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		f->zoom = 1.0;
		f->fractal_number = 1;
		f->power = 2;
		if (f->fractal_number != key - '0')
			f->fractal_number = key - '0';
		if (f->fractal_number != 8 && key == 55)
		{
			f->fractal_number = 8;
			if (f->power == 2)
				f->power++;
		}
	}
}

void	multibrot_power_switch(int key, t_fractal *f)
{
	if (key == 61 && (f->fractal_number == 1 || f->fractal_number == 7))
	{
		if (f->bind_combo_shift == 1)
			f->power += 0.1;
		else
			f->power++;
		f->fractal_number = 7;
	}
	else if (key == 45 && f->fractal_number == 7)
	{
		if (f->power == 3)
			f->fractal_number = 1;
		else
			f->fractal_number = 7;
		if (f->bind_combo_shift == 1)
			f->power -= 0.1;
		else
			f->power--;
	}
}

void	backspace_switch(int key, t_fractal *f)
{
	double	tmp;

	if (key == BACKSPACE)
	{
		tmp = f->fractal_number;
		f->fractal_number = f->tmp_fractal_number;
		f->tmp_fractal_number = tmp;
		tmp = f->shift_x;
		f->shift_x = f->tmp_shift_x;
		f->tmp_shift_x = tmp;
		tmp = f->shift_y;
		f->shift_y = f->tmp_shift_y;
		f->tmp_shift_y = tmp;
		tmp = f->zoom;
		f->zoom = f->tmp_zoom;
		f->tmp_zoom = tmp;
	}
}
