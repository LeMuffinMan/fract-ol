/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:40:50 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/26 22:22:18 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../include/fractol.h"
#include <stdlib.h>

int	init_fractal(t_fractal *f)
{
	init_tmp(f);
	init_pov(f);
	init_flag(f);
	init_index(f);
	init_switch(f);
	init_limits(f);
	return (0);
}

