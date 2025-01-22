/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:28:27 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/22 17:33:20 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// 6 fonctions :
// trier et garder ce qu'on veut

#include "../include/fractol.h"
#include <math.h>

void	colorize_pixel(int x, int y, t_img *img, int color)
// degrader a gerer ic.y ?
// je capte pas ce que je fais la
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp));
	*(unsigned int *)(img->pixels + offset) = color;
}

// couleur degueu pour thomas
// HSL ?
int	*palette_selector(int n) // on voudrait que ca plafonne sur du noir
{
	int	paletteR[] = {0xFF0000, 0xFF4500, 0xFF6347, 0xFF7F00, 0xFFB300,
			0xFFD700, 0xFFFF00, 0xEEDD82, 0xF0E68C, 0xDAA520, 0xB8860B,
			0x9ACD32, 0xADFF2F, 0x7FFF00, 0x32CD32, 0x00FF00, 0x00FA9A,
			0x20B2AA, 0x5F9EA0, 0x4682B4};
	int	paletteG[] = {0x0000FF, 0x1E90FF, 0x6495ED, 0x4169E1, 0x00008B,
			0x0000CD, 0x4682B4, 0x5F9EA0, 0xB0C4DE, 0xADD8E6, 0x87CEFA,
			0x87CEEB, 0x4682B4, 0x5F9EA0, 0x191970, 0x8A2BE2, 0x7B68EE,
			0x6A5ACD, 0x8B008B, 0x9932CC};
	int	paletteB[] = {0x008000, 0x006400, 0x228B22, 0x32CD32, 0x00FF00,
			0x7FFF00, 0x9ACD32, 0x6B8E23, 0x556B2F, 0x8FBC8F, 0x2E8B57,
			0x3CB371, 0x20B2AA, 0xADFF2F, 0x7CFC00, 0x98FB98, 0x00FA9A,
			0x00FF7F, 0x00FF00, 0x66CDAA};
	int	*palettes[] = {paletteR, paletteG, paletteB};

	if (n >= 0 && n < 3)
		return (palettes[n]);
	else if (n >= 3)
		return (palettes[n % 3]);
	return (palettes[0]);
}

// generer plusieurs palettes
// mettre la palette dans une fonction
// modifier dynamiquement
// varier jeux de palettes
int	generate_smooth_color(int iteration, double mu, int max_iterations,
		int color_modify, int palette_n)
{
	double	t;
	int		index;
	int		*palette;
	int		palette_size;

	palette = palette_selector(palette_n);
	palette_size = 20;
	t = (iteration + mu + color_modify) / max_iterations;
	// Fraction lissée
	index = (int)(t * palette_size) % palette_size;
	return (palette[index]);
}

// david tip :
//
// Les nombres de type double sont codés sur 64 bits dont :

/*     52 bits pour la mantisse */
/*     11 bits pour l'exposant */
/*     1 bit pour le signe */
/* je veux recuperer l'exposant
 * bit shift vers la gauche de 52 bits
 * puis bit shift a droite de 53 bits
 * je transforme en int : me donne le nombre de l'exposant
 *
 * */

/**
 * Interpolation linéaire entre deux couleurs
 */
/* int	interpolate_color(int color1, int color2, double t) */
/* { */
/* 	int	r; */
/* 	int	g; */
/* 	int	b;  0xFF8FBC8F 0x0000FF 000011111 */

/*  pour un integer : decaler une fois a droite == / 2   */

/* 	r = ((1 - t) * ((color1 >> 16) & 0xFF)) + (t * ((color2 >> 16) & 0xFF)); */
/* 	g = ((1 - t) * ((color1 >> 8) & 0xFF)) + (t * ((color2 >> 8) & 0xFF)); */
/* 	b = ((1 - t) * (color1 & 0xFF)) + (t * (color2 & 0xFF)); */
/* 	return ((r << 16) | (g << 8) | b); */
/* } */
/**/
/* int	generate_smooth_color(int iteration, double mu, int max_iterations) */
/* { */
/* 	int	palette_size; */
/* 	int	color1; */
/* 	int	color2; */
/* 	int palette[] = { */
/* 		0xFF0000, // Rouge */
/* 		0xFF7F00, // Orange */
/* 		0xFFFF00  // Jaune */
/* 			0x00FF00, // Vert */
/* 			0x0000FF, // Bleu */
/* 			0x4B0082, // Indigo */
/* 			0x8B00FF  // Violet */
/* 	}; */
/* 	double t = (iteration + 1 - mu) / max_iterations; // Fraction lissée */
/* 	palette_size = sizeof(palette) / sizeof(int); */
/* 	color1 = palette[(int)(t * palette_size) % palette_size]; */
/* 	color2 = palette[((int)(t * palette_size) + 1) % palette_size]; */
/* 	return (interpolate_color(color1, color2, fmod(t * palette_size, 1.0))); */
/* } */
