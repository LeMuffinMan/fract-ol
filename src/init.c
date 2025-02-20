/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:40:50 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 13:56:49 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdlib.h>

int	init_data(t_data *f)
{
	f->fractal_number = 1;
	f->escape_value = 4;
	f->max_iterations = MIN_I;
	f->shift_view.x = 0.0;
	f->shift_view.y = 0.0;
	f->zoom = 1.0;
	f->z.x = 0;
	f->z.y = 0;
	f->c.x = 0;
	f->c.y = 0;
	return (0);
}

// A PROTEGER !!!
int	init_win(t_data *f)
{
	f->mlx.mlx = mlx_init();
	if (f->mlx.mlx == NULL)
		return (-1);
	f->mlx.win = mlx_new_window(f->mlx.mlx, WINSIZE, WINSIZE, "Fractol");
	f->mlx.img.img_p = mlx_new_image(f->mlx.mlx, WINSIZE, WINSIZE);
	f->mlx.img.pixels = mlx_get_data_addr(f->mlx.img.img_p, &f->mlx.img.bpp,
			&f->mlx.img.line_len, &f->mlx.img.endian);
	f->mlx.img.bpp /= 8;
	iterate_on_pixels(f);
	return (0);
}
