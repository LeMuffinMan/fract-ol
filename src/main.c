/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:18:49 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 12:34:23 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../minilibx-linux/mlx.h"
#include <X11/X.h> //checker la doc
#include <errno.h>
#include <stddef.h> //stdlib utilise stddef : plus direct
#include <stdio.h>  //perror
#include <stdlib.h>

//revoir les exit ici 
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
		mlx_loop_end(f->mlx.mlx); // je capte pas cette fonction
		mlx_destroy_display(f->mlx.mlx);
		free(f->mlx.mlx);
	}
	exit(0); // checker la dif entre exit 1 et exit 0
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
	mlx_hook(f.mlx.win, WIN_X, 0, quit, &f);                   
	mlx_hook(f.mlx.win, KeyPress, KeyPressMask, kb_inputs, &f);
	mlx_mouse_hook(f.mlx.win, mouse_inputs, &f);
	mlx_loop(f.mlx.mlx);
	return (0);
}


