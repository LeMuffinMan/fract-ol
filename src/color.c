/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:28:27 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/26 22:41:41 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <math.h>
#include <stdlib.h>

// lire la doc pour ca !
// //render fractal ?
void	colorize_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp));
	*(unsigned int *)(img->pixels + offset) = color;
}

// A revoir
int	generate_smooth_color(int iteration, double mu, int max_iterations, t_palette *palette)
{
	double	t;
	int		index;

    if (palette == NULL) 
        return (0); 
    t = (iteration + mu) / max_iterations;
	if (t < 0) t = 0;
    if (t > 1) t = 1;
	index = (int)(t * PALETTE_SIZE) % PALETTE_SIZE;
    if (index < 0) index = 0;
    if (index >= PALETTE_SIZE) index = PALETTE_SIZE - 1;

    return (palette->palettes[palette->n][index]);
}

