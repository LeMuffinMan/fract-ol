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

//diviser en deux fichiers

int	init_win(t_fractal *f) // A PROTEGER !!!
{
	f->mlx.mlx = mlx_init();
	if (f->mlx.mlx == NULL)
		return (-1);
	f->mlx.win = mlx_new_window(f->mlx.mlx, WINSIZE_X, WINSIZE_Y, "Fractol");
	// changer selon l'input le nom de la fenetre
	f->mlx.img.img_p = mlx_new_image(f->mlx.mlx, WINSIZE_X, WINSIZE_Y);
	f->mlx.img.pixels = mlx_get_data_addr(f->mlx.img.img_p, &f->mlx.img.bpp,
			&f->mlx.img.line_len, &f->mlx.img.endian);
	f->mlx.img.bpp /= 8; // conseil pour afficher 4 pixels d'un coup ?
	return (0);
}

void init_tmp(t_fractal *f)
{
	f->tmp_shift_x = 0.0;
	f->tmp_shift_y = 0.0;
	f->tmp_zoom = 1.0;
}

void init_pov(t_fractal *f)
{
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1.0;
	f->speed_factor = 0.02; // a rename pour zoom
}

void init_flag(t_fractal *f)
{
	f->zooming_out = 0;
	f->zooming_in = 0;
	f->zooming_out_start = 0;
	f->zooming_in_start = 0;
	f->psyche_switch = 0;
	f->debug = 0;
	f->traveling = 0;
	f->origin = 0;
	f->psychedelic_colors = 0;
	f->bind_combo = 0;
	f->bind_combo_z = 0;
	f->bind_combo_t = 0;
	f->red_toggle = 1;
	f->green_toggle = 1;
	f->blue_toggle = 1;
}

void init_index(t_fractal *f)
{
	f->fractal_number = 0;
	f->palette.n = 0;
}

void init_switch(t_fractal *f)
{
	f->switch_iterations = 20;
	f->power = 2;
}

void init_limits(t_fractal *f)
{
	f->escape_value = 4;
	f->max_iterations = MIN_I;
}

void init_coords(t_fractal *f)
{
	f->j_x = 0;
	f->j_y = 0;
	f->mouse_x = 0;
	f->mouse_y = 0;
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
// revoir apres avoir ranger le .h
int	init_fractal(t_fractal *f)
{
	init_tmp(f);
	init_pov(f);
	init_flag(f);
	init_index(f);
	init_switch(f);
	init_limits(f);
	init_coords(f);
	f->t = 0;
	f->tc = 0.01;
	f->mu = 0;
	return (0);
}

