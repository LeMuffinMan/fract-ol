/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:14:39 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 19:36:48 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	wheel_zoom_out(int key, int x, int y, t_data *f)
{
	if (key == MOUSE_WHEEL_DOWN)
	{
		f->zoom *= 1.1;
		f->shift_view.x -= (x - WINSIZE / 2.0) * f->zoom / 1000;
		f->shift_view.y += (y - WINSIZE / 2.0) * f->zoom / 1000;
	}
}

void	wheel_zoom_in(int key, int x, int y, t_data *f)
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
}

void	wheel_zoom(int key, int x, int y, t_data *f)
{
	wheel_zoom_out(key, x, y, f);
	wheel_zoom_in(key, x, y, f);
}
