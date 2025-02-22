/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_switch_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:04:13 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/22 10:53:13 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/fractol_bonus.h"

void	psyche_switch(int key, t_data *f)
{
	if (key == P)
	{
		if (f->flags.psyche_switch == 0)
			f->flags.psyche_switch = 1;
		else
			f->flags.psyche_switch = 0;
	}
}

void	num_fractal_switch(int key, t_data *f)
{
	if (key >= 49 && key <= 55)
	{
		f->shift_view.x = 0.0;
		f->shift_view.y = 0.0;
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
		f->max_iterations = 1;
		f->flags.fractal_switch = 1;
	}
}

void	multibrot_power_switch(int key, t_data *f)
{
	if (key == 61 && (f->fractal_number == 1 || f->fractal_number == 7))
	{
		if (f->flags.bind_combo_shift == 1)
			f->power += 0.1;
		else
			f->power++;
		f->fractal_number = 7;
		f->max_iterations = 1;
		f->flags.fractal_switch = 1;
	}
	else if (key == 45 && f->fractal_number == 7)
	{
		if (f->power == 3)
			f->fractal_number = 1;
		else
			f->fractal_number = 7;
		if (f->flags.bind_combo_shift == 1)
			f->power -= 0.1;
		else
			f->power--;
		f->max_iterations = 1;
		f->flags.fractal_switch = 1;
	}
}

void	backspace_switch(int key, t_data *f)
{
	double	tmp;

	if (key == BACKSPACE)
	{
		tmp = f->fractal_number;
		f->fractal_number = f->tmp.fractal_number;
		f->tmp.fractal_number = tmp;
		tmp = f->shift_view.x;
		f->shift_view.x = f->tmp.shift_x;
		f->tmp.shift_x = tmp;
		tmp = f->shift_view.y;
		f->shift_view.y = f->tmp.shift_y;
		f->tmp.shift_y = tmp;
		tmp = f->zoom;
		f->zoom = f->tmp.zoom;
		f->tmp.zoom = tmp;
	}
}
