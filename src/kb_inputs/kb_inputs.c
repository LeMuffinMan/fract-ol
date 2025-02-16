/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_inputs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:53:43 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 17:18:51 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	arrows(int key, t_data *f)
{
	if (key == RIGHT)
		f->shift_view.x += (0.2 * f->zoom);
	else if (key == LEFT)
		f->shift_view.x -= (0.2 * f->zoom);
	else if (key == DOWN)
			f->shift_view.y -= (0.2 * f->zoom);
	else if (key == UP)
			f->shift_view.y += (0.2 * f->zoom);
	return (key);
}

int	kb_inputs(int key, t_data *f)
{
	if (key == WIN_X || key == ESC)
		quit(f);
	/* combo_keys(key, f); */
	/* arrows(key, f); */
	/* pav_num_operators(key, f); */
	/* psyche_switch(key, f); */
	/* debug_switch(key, f); */
	/* num_fractal_switch(key, f); */
	/* color_shift(key, f); */
	/* multibrot_power_switch(key, f); */
	/* backspace_switch(key, f); */
	/* julia_moves(key, f); */
	/* julia_constant_selector(key, f); */
	/* animation_speed_keys(key, f); */
	/* space_pause(key, f); */
	/* iterate_on_pixels(f); */
	return (0);
}
