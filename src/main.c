/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:18:49 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/19 16:03:02 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <X11/X.h> 

int	main(int ac, char **av)
{
	t_data	f;

	init_data(&f);
	check_input(ac, av, &f);
	init_win(&f);
	mlx_hook(f.mlx.win, WIN_X, 0, quit, &f);
	mlx_hook(f.mlx.win, KeyRelease, KeyReleaseMask, kb_inputs, &f);
	mlx_mouse_hook(f.mlx.win, mouse_inputs, &f);
	mlx_loop(f.mlx.mlx);
	return (0);
}
