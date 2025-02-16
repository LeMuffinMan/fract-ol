/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:02:57 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 17:19:41 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	space_pause(int key, t_fractal *f)
{
	if (key == SPACE)
	{
		if (f->flags.traveling == 1)
			f->flags.traveling = 0;
		else
			f->flags.traveling = 1;
	}
}

void	animation_speed_keys(int key, t_fractal *f)
{
	if (key == PLUS && f->flags.bind_combo_ctrl_l == 1)
		f->tc *= 2;
	if (key == MINUS && f->flags.bind_combo_ctrl_l == 1)
		f->tc /= 2;
}
