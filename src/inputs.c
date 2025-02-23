/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:42:48 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/19 15:24:46 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_inputs(int key, int x, int y, t_data *f)
{
	if (key == MOUSE_WHEEL_UP)
	{
		f->zoom *= 0.9;
		f->shift_view.x += (x - (WINSIZE >> 1)) * f->zoom * 0.001;
		f->shift_view.y -= (y - (WINSIZE >> 1)) * f->zoom * 0.001;
	}
	else if (key == MOUSE_WHEEL_DOWN)
	{
		f->zoom *= 1.1;
		f->shift_view.x -= (x - (WINSIZE >> 1)) * f->zoom * 0.001;
		f->shift_view.y += (y - (WINSIZE >> 1)) * f->zoom * 0.001;
	}
	render_fractal(f);
	return (key);
}

int	kb_inputs(int key, t_data *f)
{
	if (key == ESC)
		quit(f);
	else if (key == PLUS && f->max_iterations < MAX_I)
		f->max_iterations++;
	else if (key == MINUS && f->max_iterations > 1)
		f->max_iterations--;
	render_fractal(f);
	return (0);
}
