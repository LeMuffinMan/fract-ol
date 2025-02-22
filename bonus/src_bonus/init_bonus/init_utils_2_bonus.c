/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:01:48 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 15:31:57 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/fractol_bonus.h"
#include "../../../minilibx-linux/mlx.h"
#include <stdlib.h>

// A PROTEGER !!!
int	init_win(t_data *f)
{
	f->mlx.mlx = mlx_init();
	if (f->mlx.mlx == NULL)
		return (-1);
	f->mlx.win = mlx_new_window(f->mlx.mlx, WINSIZE_X, WINSIZE_Y, "Fractol");
	f->mlx.img.img_p = mlx_new_image(f->mlx.mlx, WINSIZE_X, WINSIZE_Y);
	f->mlx.img.pixels = mlx_get_data_addr(f->mlx.img.img_p, &f->mlx.img.bpp,
			&f->mlx.img.line_len, &f->mlx.img.endian);
	f->mlx.img.bpp /= 8;
	return (0);
}

void	init_tmp(t_data *f)
{
	f->tmp.shift_x = 0.0;
	f->tmp.shift_y = 0.0;
	f->tmp.zoom = 1.0;
	f->tmp.fractal_number = 0;
}

void	init_pov(t_data *f)
{
	f->shift_view.x = 0.0;
	f->shift_view.y = 0.0;
	f->zoom = 1.0;
	f->speed_factor = 0.02;
}

//du coup zooming_out_start es pas declare ?
void	init_flag(t_data *f)
{
	f->flags.zooming_out = 0;
	f->flags.zooming_in = 0;
	f->flags.zooming_out_start = 0;
	f->flags.zooming_in_start = 0;
	f->flags.psyche_switch = 0;
	f->flags.debug = 0;
	f->flags.traveling = 0;
	f->flags.origin = 0;
	f->flags.psychedelic_colors = 0;
	f->flags.bind_combo_shift = 0;
	f->flags.bind_combo_alt_l = 0;
	f->flags.bind_combo_ctrl_l = 0;
	f->flags.red_toggle = 1;
	f->flags.green_toggle = 1;
	f->flags.blue_toggle = 1;
}
