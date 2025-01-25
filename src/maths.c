/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:17:17 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/23 18:30:26 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <math.h>

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

double	norm_complex(t_complex z)
{
	return (sqrt(z.x * z.x + z.y * z.y));
}

void	burning_ship(t_fractal *f)
{
	double	tmp;

	f->z.x = fabs(f->z.x);
	f->z.y = fabs(f->z.y);
	tmp = 2 * f->z.x * f->z.y + f->c.y;
	f->z.x = f->z.x * f->z.x - f->z.y * f->z.y + f->c.x;
	f->z.y = tmp;
}

void	tricorn(t_fractal *f)
{
	double	tmp;

	tmp = -2 * f->z.x * f->z.y + f->c.y;
	f->z.x = f->z.x * f->z.x - f->z.y * f->z.y + f->c.x;
	f->z.y = tmp;
}

void	multibrot(t_fractal *f)
{
	double	tmp;
	double	n;

	n = f->power;
	tmp = pow(f->z.x * f->z.x + f->z.y * f->z.y, (n - 1) / 2.0) * cos(n
			* atan2(f->z.y, f->z.x)) + f->c.x;
	f->z.y = pow(f->z.x * f->z.x + f->z.y * f->z.y, (n - 1) / 2.0) * sin(n
			* atan2(f->z.y, f->z.x)) + f->c.y;
	f->z.x = tmp;
}

void	calculate_f(t_fractal *f) // a optimiser
{
	if (f->fractal_number == 1 || f->fractal_number == 4)
		f->z = sum_complex(square_complex(f->z), f->c); // choisir la strat ?
	if (f->fractal_number == 2 || f->fractal_number == 5)
		burning_ship(f);
	if (f->fractal_number == 3 || f->fractal_number == 6)
		tricorn(f);
	if (f->fractal_number == 7 || f->fractal_number == 8) // multibrot
		multibrot(f);
}
