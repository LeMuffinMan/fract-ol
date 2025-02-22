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
