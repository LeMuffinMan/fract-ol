/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:17:17 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/19 16:01:25 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <math.h>

// le faire direct en dur plutot que de faire une fonction ?
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

//retrouver comment on faisait sqrt voir si c'est plus rentable ?
double	norm_complex(t_coords z)
{
	return (sqrt(z.x * z.x + z.y * z.y));
}



