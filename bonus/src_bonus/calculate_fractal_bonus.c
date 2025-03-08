/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:16:15 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 14:17:11 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/fractol_bonus.h"
#include <math.h>

void	burning_ship(t_data *f, t_coords *z, t_coords *c)
{
	(void)f;
	z->x = fabsl(z->x);
	z->y = fabsl(z->y);
	*z = sum_complex(square_complex(*z), *c);
}

void	tricorn(t_data *f, t_coords *z, t_coords *c)
{
	(void)f;
	z->y = -z->y; // Conjugate of z
	*z = sum_complex(square_complex(*z), *c);
}

void	multibrot(t_data *f, t_coords *z, t_coords *c)
{
	double	tmp;
	double	n;

	n = f->power;
	(void)f;
	tmp = pow(z->x * z->x + z->y * z->y, (n - 1) / 2.0) * cos(n
			* atan2(z->y, z->x)) + c->x;
	z->y = pow(z->x * z->x + z->y * z->y, (n - 1) / 2.0) * sin(n
			* atan2(z->y, z->x)) + c->y;
	z->x = tmp;
}

void	calculate_f(t_data *f, t_coords *z, t_coords *c)
{
	if (f->fractal_number == 1 || f->fractal_number == 4)
	{
		*z = sum_complex(square_complex(*z), *c); // Use local z and c
	}
	if (f->fractal_number == 2 || f->fractal_number == 5)
	{
		burning_ship(f, z, c); // Pass local z and c
	}
	if (f->fractal_number == 3 || f->fractal_number == 6)
	{
		tricorn(f, z, c); // Pass local z and c
	}
	if (f->fractal_number == 7 || f->fractal_number == 8)
	{
		multibrot(f, z, c); // Pass local z and c
	}
}
