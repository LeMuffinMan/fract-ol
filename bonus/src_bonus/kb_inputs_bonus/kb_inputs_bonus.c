/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_inputs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:53:43 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/22 10:55:03 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/fractol_bonus.h"

int	arrows(int key, t_data *f)
{
	if (key == RIGHT)
		f->shift_view.x += (0.2 * f->zoom);
	else if (key == LEFT)
		f->shift_view.x -= (0.2 * f->zoom);
	else if (key == DOWN)
	{
		if (f->flags.bind_combo_shift == 1)
			f->zoom *= 0.7;
		else
			f->shift_view.y -= (0.2 * f->zoom);
	}
	else if (key == UP)
	{
		if (f->flags.bind_combo_shift == 1)
			f->zoom *= 1.3;
		else
			f->shift_view.y += (0.2 * f->zoom);
	}
	return (key);
}

void	combo_keys(int key, t_data *f)
{
	if (key == SHIFT)
	{
		if (f->flags.bind_combo_shift == 0)
			f->flags.bind_combo_shift = 1;
		else if (f->flags.bind_combo_shift == 1)
			f->flags.bind_combo_shift = 0;
	}
	if (key == ALT_L)
	{
		if (f->flags.bind_combo_alt_l == 0)
			f->flags.bind_combo_alt_l = 1;
		else if (f->flags.bind_combo_alt_l == 1)
			f->flags.bind_combo_alt_l = 0;
	}
	if (key == CTRL_L)
	{
		if (f->flags.bind_combo_ctrl_l == 0)
			f->flags.bind_combo_ctrl_l = 1;
		else if (f->flags.bind_combo_ctrl_l == 1)
			f->flags.bind_combo_ctrl_l = 0;
	}
}

int	shift_toggle(int key, t_data *f)
{
	if (key == SHIFT)
		f->flags.bind_combo_shift = 0;
	else if (key == CTRL_L)
		f->flags.bind_combo_ctrl_l = 0;
	else if (key == ALT_L)
		f->flags.bind_combo_alt_l = 0;
	return (0);
}

int	kb_inputs(int key, t_data *f)
{
	if (key == WIN_X || key == ESC)
		quit(f);
	combo_keys(key, f);
	arrows(key, f);
	pav_num_operators(key, f);
	psyche_switch(key, f);
	num_fractal_switch(key, f);
	color_shift(key, f);
	multibrot_power_switch(key, f);
	backspace_switch(key, f);
	julia_moves(key, f);
	julia_constant_selector(key, f);
	animation_speed_keys(key, f);
	space_pause(key, f);
	if (f->flags.fractal_switch == 0)
		iterate_on_pixels(f);
	else
		first_render(f);
	return (0);
}
