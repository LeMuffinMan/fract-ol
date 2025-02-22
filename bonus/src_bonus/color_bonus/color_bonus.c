/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:28:27 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/22 10:23:29 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include_bonus/fractol_bonus.h"
#include <math.h>
#include <stdlib.h>

void	bit_shift_rgb(int i, int *color, t_data *f)
{
	t_color	colors;
	double	t;

	t = (double)i / f->max_iterations;
	colors.r = (char)(9 * (1 - t) * t * t * t * t * 255);
	colors.g = (char)(15 * (1 - t) * (1 - t) * t * t * 255);
	colors.b = (char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	*color = colors.color;
}

// lire la doc pour ca !
// faire un fichier avec les fonctions speciales minilibx
int	colorize_pixel(int x, int y, t_data *f, int color, int i)
{
	int	offset;

	if ((f->z.x * f->z.x) + (f->z.y * f->z.y) > f->escape_value)
	{
		if (f->flags.psychedelic_colors == 1)
		{
			f->mu = log(log(norm_complex(f->z))) / log(2);
			color = generate_smooth_color(i, f->mu, f->max_iterations,
					&f->palette);
		}
		else
			bit_shift_rgb(i, &color, f);
		offset = (y * f->mlx.img.line_len) + (x * (f->mlx.img.bpp));
		*(unsigned int *)(f->mlx.img.pixels + offset) = color;
		return (1);
	}
	return (0);
}

// renommer et rechecker
int	generate_smooth_color(int iteration, double mu, int max_iterations,
		t_palette *palette)
{
	double	t;
	int		index;

	if (palette == NULL)
		return (0);
	t = (iteration + mu) / max_iterations;
	if (t < 0)
		t = 0;
	if (t > 1)
		t = 1;
	index = (int)(t * PALETTE_SIZE) % PALETTE_SIZE;
	if (index < 0)
		index = 0;
	if (index >= PALETTE_SIZE)
		index = PALETTE_SIZE - 1;
	return (palette->palettes[palette->n][index]);
}
