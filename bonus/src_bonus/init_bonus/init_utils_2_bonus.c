/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:01:48 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/22 10:53:44 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/fractol_bonus.h"

void	init_tmp(t_data *f)
{
	f->tmp.shift_x = 0.0;
	f->tmp.shift_y = 0.0;
	f->tmp.zoom = 1.0;
	f->tmp.fractal_number = 0;
}

void	init_pov(t_data *f)
{
	f->shift_view.x = 0.0;
	f->shift_view.y = 0.0;
	f->zoom = 1.0;
	f->speed_factor = 0.02;
}

void	init_flag(t_data *f)
{
	f->flags.zooming_out = 0;
	f->flags.zooming_in = 0;
	f->flags.zooming_out_start = 0;
	f->flags.zooming_in_start = 0;
	f->flags.psyche_switch = 0;
	f->flags.traveling = 0;
	f->flags.origin = 0;
	f->flags.psychedelic_colors = 0;
	f->flags.bind_combo_shift = 0;
	f->flags.bind_combo_alt_l = 0;
	f->flags.bind_combo_ctrl_l = 0;
	f->flags.red_toggle = 1;
	f->flags.green_toggle = 1;
	f->flags.blue_toggle = 1;
	f->flags.fractal_switch = 1;
}
