/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:01:17 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 15:31:07 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/fractol_bonus.h"

void	init_index(t_data *f)
{
	f->fractal_number = 0;
	f->palette.n = 0;
}

void	init_switch(t_data *f)
{
	f->switch_iterations = 20;
	f->power = 2;
}

void	init_limits(t_data *f)
{
	f->escape_value = 4;
	f->max_iterations = 1;
}

void	init_coords(t_data *f)
{
	f->shift_view.x = 0;
	f->shift_view.y = 0;
	f->julia_constant.x = 0;
	f->julia_constant.y = 0;
	f->mouse.x = 0;
	f->mouse.y = 0;
	f->zooming_out_coords.x = 0;
	f->zooming_out_coords.y = 0;
	f->z.x = 0;
	f->z.y = 0;
	f->c.x = 0;
	f->c.y = 0;
	f->o.x = 0;
	f->o.y = 0;
	f->a.x = 0;
	f->a.y = 0;
	f->d.x = 0;
	f->d.y = 0;
}

void	init_anims(t_data *f)
{
	init_coords(f);
	f->t = 0;
	f->tc = 0.01;
	f->mu = 0;
}
