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

#include "../../include_bonus/fractol_bonus.h"
#include "../../../minilibx-linux/mlx.h"
#include <stdlib.h>

int	init_data(t_data *f)
{
	init_tmp(f);
	init_pov(f);
	init_flag(f);
	init_index(f);
	init_switch(f);
	init_limits(f);
	init_anims(f);
	return (0);
}

int	init_win(t_data *f)
{
	f->mlx.mlx = mlx_init();
	if (f->mlx.mlx == NULL)
		quit(f);
	f->mlx.win = mlx_new_window(f->mlx.mlx, WINSIZE, WINSIZE, "Fractol");
	if (f->mlx.win == NULL)
		quit(f);
	f->mlx.img.img_p = mlx_new_image(f->mlx.mlx, WINSIZE, WINSIZE);
	if (f->mlx.img.img_p == NULL)
		quit(f);
	f->mlx.img.pixels = mlx_get_data_addr(f->mlx.img.img_p, &f->mlx.img.bpp,
			&f->mlx.img.line_len, &f->mlx.img.endian);
	if (f->mlx.img.pixels == NULL)
		quit(f);
	f->mlx.img.bpp /= 8;
	return (0);
}
