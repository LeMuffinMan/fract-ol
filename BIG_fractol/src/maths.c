/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:17:17 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 16:07:13 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <math.h>

t_coords	sum_complex(t_coords z1, t_coords z2)
{
	t_coords	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_coords	square_complex(t_coords z)
{
	t_coords	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

double	norm_complex(t_coords z)
{
	return (sqrt(z.x * z.x + z.y * z.y));
}

double	scale(double unscaled_num, double new_min, double new_max,
		double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min)
		+ new_min);
}

void	travel_between_fractals(t_fractal *f)
{
	f->flags.traveling = 1;
	f->t += f->tc;
	f->julia_constant.x = f->o.x + ((sin(f->t) + 1) * 0.5) * f->d.x;
	f->julia_constant.y = f->o.y + ((sin(f->t) + 1) * 0.5) * f->d.y;
	iterate_on_pixels(f);
	mlx_do_sync(f->mlx.mlx);
}
