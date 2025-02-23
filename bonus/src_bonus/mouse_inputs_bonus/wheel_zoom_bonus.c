/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wheel_zoom_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:14:39 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/22 10:45:43 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/fractol_bonus.h"

void	wheel_zoom_out(int key, int x, int y, t_data *f)
{
	if (key == MOUSE_WHEEL_DOWN && f->flags.bind_combo_ctrl_l == 0
		&& f->flags.bind_combo_alt_l == 0 && f->flags.bind_combo_shift == 0)
	{
		f->zoom *= 1.1;
		f->shift_view.x -= (x - (WINSIZE >> 1)) * f->zoom * 0.001;
		f->shift_view.y += (y - (WINSIZE >> 1)) * f->zoom * 0.001;
	}
}

void	wheel_zoom_in(int key, int x, int y, t_data *f)
{
	if (key == MOUSE_WHEEL_UP && f->flags.bind_combo_shift == 0
		&& f->flags.bind_combo_ctrl_l == 0 && f->flags.bind_combo_alt_l == 0)
	{
		f->zoom *= 0.9;
		f->shift_view.x += (x - (WINSIZE >> 1)) * f->zoom * 0.001;
		f->shift_view.y -= (y - (WINSIZE >> 1)) * f->zoom * 0.001;
	}
}

void	wheel_zoom(int key, int x, int y, t_data *f)
{
	wheel_zoom_out(key, x, y, f);
	wheel_zoom_in(key, x, y, f);
}
