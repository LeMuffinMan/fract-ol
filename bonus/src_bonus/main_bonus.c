/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:18:49 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/22 10:50:28 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"
#include "../include_bonus/fractol_bonus.h"
#include "../../libft/include/libft.h"
#include <X11/X.h> //checker la doc
#include <stdlib.h>

int	quit(t_data *f)
{
	if (!f)
		exit(1);
	if (f->mlx.img.img_p)
		mlx_destroy_image(f->mlx.mlx, f->mlx.img.img_p);
	if (f->mlx.win)
		mlx_destroy_window(f->mlx.mlx, f->mlx.win);
	if (f->mlx.mlx)
	{
		mlx_loop_end(f->mlx.mlx);
		mlx_destroy_display(f->mlx.mlx);
		free(f->mlx.mlx);
	}
	exit(0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* presets julia */
/* 0.3 0.5  */
/* –0,038088 0.97 */

int	main(int ac, char **av)
{
	t_data	f;

	init_data(&f);
	check_input(ac, av, &f);
	init_win(&f);
	palette_init(&f.palette);
	iterate_on_pixels(&f);
	mlx_hook(f.mlx.win, WIN_X, 0, quit, &f);
	mlx_hook(f.mlx.win, KeyPress, KeyPressMask, kb_inputs, &f);
	mlx_hook(f.mlx.win, KeyRelease, KeyReleaseMask, shift_toggle, &f);
	mlx_mouse_hook(f.mlx.win, mouse_inputs, &f);
	mlx_hook(f.mlx.win, MotionNotify, PointerMotionMask, get_mouse_coords, &f);
	mlx_loop_hook(f.mlx.mlx, update_animations, &f);
	mlx_loop(f.mlx.mlx);
	return (0);
}
