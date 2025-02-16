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

#include "../include/fractol.h"
#include <math.h>

void	calculate_f(t_data *f)
{
	if (f->fractal_number == 1 || f->fractal_number == 2)
		f->z = sum_complex(square_complex(f->z), f->c);
}
