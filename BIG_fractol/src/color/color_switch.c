/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_switch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:50:37 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 17:16:12 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	switch_red(t_fractal *f)
{
	if (f->flags.psychedelic_colors == 1)
		f->palette.n = 0;
	else
	{
		if (f->flags.red_toggle == 0)
			f->flags.red_toggle = 1;
		else
			f->flags.red_toggle = 0;
	}
}

void	switch_green(t_fractal *f)
{
	if (f->flags.psychedelic_colors == 1)
		f->palette.n = 1;
	else
	{
		if (f->flags.blue_toggle == 0)
			f->flags.blue_toggle = 1;
		else
			f->flags.blue_toggle = 0;
	}
}

void	switch_blue(t_fractal *f)
{
	if (f->flags.psychedelic_colors == 1)
		f->palette.n = 2;
	else
	{
		if (f->flags.green_toggle == 0)
			f->flags.green_toggle = 1;
		else
			f->flags.green_toggle = 0;
	}
}

void	color_shift(int key, t_fractal *f)
{
	if (key == R)
		switch_red(f);
	else if (key == B)
		switch_blue(f);
	else if (key == G)
		switch_green(f);
	else if (key == E)
	{
		if (f->flags.psychedelic_colors == 0)
			f->flags.psychedelic_colors = 1;
		else
			f->flags.psychedelic_colors = 0;
	}
}
