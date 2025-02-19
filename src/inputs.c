/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:42:48 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/19 12:43:00 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h> //remplacer par printf !

int	mouse_inputs(int key, int x, int y, t_data *f)
{
	double	relative_x;
	double	relative_y;

	if (key == MOUSE_WHEEL_UP)
	{
		f->zoom *= 0.9;
		relative_x = (x - WINSIZE / 2.0) * f->zoom / 1000;
		relative_y = (y - WINSIZE / 2.0) * f->zoom / 1000;
		f->shift_view.x += relative_x;
		f->shift_view.y -= relative_y;
	}
	else if (key == MOUSE_WHEEL_DOWN)
	{
		f->zoom *= 1.1;
		f->shift_view.x -= (x - WINSIZE / 2.0) * f->zoom / 1000;
		f->shift_view.y += (y - WINSIZE / 2.0) * f->zoom / 1000;
	}
	iterate_on_pixels(f);
	return (key);
}

int	kb_inputs(int key, t_data *f)
{
	//corriger ici : win X n'y passera jamais
	if (key == WIN_X || key == ESC)
		quit(f);
	return (0);
}
