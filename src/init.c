/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:40:50 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/23 17:40:53 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* reorganiser */

#include "../include/fractol.h"
#include <stdlib.h>

int	init_win(t_fractal *f) // A PROTEGER !!!
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		return (-1);
	f->win = mlx_new_window(f->mlx, WINSIZE_X, WINSIZE_Y, "Fractol");
		// changer selon l'input le nom de la fenetre
	f->img.img_p = mlx_new_image(f->mlx, WINSIZE_X, WINSIZE_Y);
	f->img.pixels = mlx_get_data_addr(f->img.img_p, &f->img.bpp,
			&f->img.line_len, &f->img.endian);
	f->img.bpp /= 8; // conseil pour afficher 4 pixels d'un coup ?
	return (0);
}

int	init_fra(t_fractal *f)
{
	f->fractal_number = 0;
	f->escape_value = 4; // pour mandelbrot : hypothenus et pythagore
	f->max_iterations = 100;
	f->switch_iterations = 100;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1.0;
	f->tmp_shift_x = 0.0;
	f->tmp_shift_y = 0.0;
	f->tmp_zoom = 1.0;
	f->bind_combo = 0;
	f->modify_color = 0;
	f->palette_n = 1;
	f->psychedelic_colors = 0;
	f->power = 2;
	// a move
	f->j_x = 0;
	f->j_y = 0;
	f->mouse_x = 0;
	f->mouse_y = 0;
	return (0);
}
