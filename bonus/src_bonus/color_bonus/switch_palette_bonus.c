/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_palette.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:52:34 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 16:26:34 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/fractol_bonus.h"

void	switch_next_palette(t_data *f)
{
	if (f->palette.n == 2)
		f->palette.n = 0;
	else if (f->palette.n < 2)
	{
		if (f->palette.n == 2)
			f->palette.n = 0;
		else
			f->palette.n++;
	}
}

void	switch_prev_palette(t_data *f)
{
	if (f->palette.n == 0)
		f->palette.n = 2;
	else if (f->palette.n > 0)
	{
		if (f->palette.n == 0)
			f->palette.n = 2;
		else
			f->palette.n--;
	}
}

void	switch_palette(int key, t_data *f)
{
	if (key == MOUSE_L && f->flags.bind_combo_alt_l == 1)
		switch_prev_palette(f);
	else if (key == MOUSE_R && f->flags.bind_combo_alt_l == 1)
		switch_next_palette(f);
}
