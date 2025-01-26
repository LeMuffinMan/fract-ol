/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:28:27 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/23 18:30:25 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <math.h>

// lire la doc pour ca !
void	colorize_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp));
	*(unsigned int *)(img->pixels + offset) = color;
}

/* void	init_palette_R(int palette_R[20]) */
/* { */
/* 	palette_R[0] = 0x000000; // Noir */
/* 	palette_R[1] = 0x330000; // Rouge très sombre (dominance de noir) */
/* 	palette_R[2] = 0x660000; // Rouge profond */
/* 	palette_R[3] = 0x990000; // Rouge intense */
/* 	palette_R[4] = 0xCC0000; // Rouge vif foncé */
/* 	palette_R[5] = 0xFF0000; // Rouge pur */
/* 	palette_R[6] = 0xFF4500; // Rouge orangé vif (Orange Red) */
/* 	palette_R[7] = 0xFF6347; // Tomate */
/* 	palette_R[8] = 0xFF7F50; // Corail */
/* 	palette_R[9] = 0xFFA500; // Orange pur */
/* 	palette_R[10] = 0xFFB347; // Orange clair */
/* 	palette_R[11] = 0xFFD700; // Jaune doré */
/* 	palette_R[12] = 0xFFA07A; // Saumon clair */
/* 	palette_R[13] = 0xCD5C5C; // Rouge saumon foncé */
/* 	palette_R[14] = 0x8B0000; // Rouge bordeaux foncé */
/* 	palette_R[15] = 0x5C0000; // Rouge brunâtre très foncé */
/* 	palette_R[16] = 0x330000; // Rouge très sombre */
/* 	palette_R[17] = 0x220000; // Rouge noirâtre */
/* 	palette_R[18] = 0x110000; // Rouge très sombre (presque noir) */
/* 	palette_R[19] = 0x000000; // Noir */
/* } */
/**/
/* void	init_palette_B(int palette_B[20]) */
/* { */
/* 	palette_B[0] = 0x000000; // Noir */
/* 	palette_B[1] = 0x000033; // Bleu très sombre (dominance de noir) */
/* 	palette_B[2] = 0x000066; // Bleu profond */
/* 	palette_B[3] = 0x000099; // Bleu intense */
/* 	palette_B[4] = 0x0000CC; // Bleu vif foncé */
/* 	palette_B[5] = 0x0000FF; // Bleu pur */
/* 	palette_B[6] = 0x1E90FF; // Bleu dodger (un bleu vif) */
/* 	palette_B[7] = 0x4682B4; // Bleu acier */
/* 	palette_B[8] = 0x5F9EA0; // Bleu grisâtre */
/* 	palette_B[9] = 0x87CEEB; // Bleu ciel clair */
/* 	palette_B[10] = 0x00BFFF; // Bleu profond clair (Deep Sky Blue) */
/* 	palette_B[11] = 0xADD8E6; // Bleu clair (Light Blue) */
/* 	palette_B[12] = 0xB0E0E6; // Bleu pâle (Powder Blue) */
/* 	palette_B[13] = 0x191970; // Bleu minuit (Midnight Blue) */
/* 	palette_B[14] = 0x4169E1; // Bleu royal */
/* 	palette_B[15] = 0x00008B; // Bleu marine */
/* 	palette_B[16] = 0x000033; // Bleu très sombre */
/* 	palette_B[17] = 0x000022; // Bleu noirâtre */
/* 	palette_B[18] = 0x000011; // Bleu très sombre (presque noir) */
/* 	palette_B[19] = 0x000000; // Noir */
/* } */
/**/
/* void	init_palette_G(int palette_G[20]) */
/* { */
/* 	palette_G[0] = 0x000000; // Noir */
/* 	palette_G[1] = 0x002200; // Vert très foncé (dominance de noir) */
/* 	palette_G[2] = 0x004400; // Vert foncé */
/* 	palette_G[3] = 0x006600; // Vert dense */
/* 	palette_G[4] = 0x008000; // Vert standard */
/* 	palette_G[5] = 0x228B22; // Vert forêt */
/* 	palette_G[6] = 0x6B8E23; // Vert olive */
/* 	palette_G[7] = 0x9ACD32; // Vert jaunâtre */
/* 	palette_G[8] = 0xADFF2F; // Vert jaune vif */
/* 	palette_G[9] = 0xF0E68C; // Kaki clair */
/* 	palette_G[10] = 0xFFFF00; // Jaune pur */
/* 	palette_G[11] = 0xFFD700; // Doré */
/* 	palette_G[12] = 0xFFC000; // Jaune orangé */
/* 	palette_G[13] = 0xB8860B; // Jaune foncé doré */
/* 	palette_G[14] = 0x808000; // Olive foncé */
/* 	palette_G[15] = 0x556B2F; // Olive très foncé */
/* 	palette_G[16] = 0x2F4F4F; // Vert gris très foncé */
/* 	palette_G[17] = 0x004400; // Vert foncé */
/* 	palette_G[18] = 0x002200; // Vert très foncé (presque noir) */
/* 	palette_G[19] = 0x000000; // Noir */
/* } */

void init_palette_R(int palette_R[20])
{
    palette_R[0] = 0x000000; // Noir
    palette_R[1] = 0x330000; // Rouge très sombre
    palette_R[2] = 0x660000; // Rouge profond
    palette_R[3] = 0x990000; // Rouge intense
    palette_R[4] = 0xCC0000; // Rouge vif foncé
    palette_R[5] = 0xFF0000; // Rouge pur
    palette_R[6] = 0xFF4C4C; // Rouge clair
    palette_R[7] = 0xFF8080; // Rouge pâle
    palette_R[8] = 0xFFB3B3; // Rose très clair
    palette_R[9] = 0xFFCCCC; // Rose pâle
    palette_R[10] = 0xFFD9D9; // Rose clair
    palette_R[11] = 0xFFEBEB; // Très clair
    palette_R[12] = 0xFFE6E6; // Pâle
    palette_R[13] = 0xFFE0E0; // Rose pâle très clair
    palette_R[14] = 0xFF9999; // Rosé très clair
    palette_R[15] = 0xF2D7D7; // Rose presque blanc
    palette_R[16] = 0xE6B7B7; // Rose clair
    palette_R[17] = 0xCC6E6E; // Rouge clair
    palette_R[18] = 0x990000; // Rouge intense
    palette_R[19] = 0xFFFFFF; // Blanc
}

void init_palette_B(int palette_B[20])
{
    palette_B[0] = 0x000000; // Noir
    palette_B[1] = 0x000033; // Bleu très sombre
    palette_B[2] = 0x000066; // Bleu profond
    palette_B[3] = 0x000099; // Bleu intense
    palette_B[4] = 0x0000CC; // Bleu vif foncé
    palette_B[5] = 0x0000FF; // Bleu pur
    palette_B[6] = 0x4C4CFF; // Bleu clair
    palette_B[7] = 0x8080FF; // Bleu pâle
    palette_B[8] = 0xA6A6FF; // Bleu très pâle
    palette_B[9] = 0xB3B3FF; // Bleu clair pâle
    palette_B[10] = 0xCCCCFF; // Bleu très clair
    palette_B[11] = 0xE0E0FF; // Bleu très pâle
    palette_B[12] = 0xF2F2FF; // Bleu presque blanc
    palette_B[13] = 0xE6E6FF; // Très pâle
    palette_B[14] = 0xB3B3FF; // Clair
    palette_B[15] = 0x8080FF; // Très clair
    palette_B[16] = 0x4C4CFF; // Bleu clair
    palette_B[17] = 0x0000CC; // Bleu vif foncé
    palette_B[18] = 0x000099; // Bleu intense
    palette_B[19] = 0xFFFFFF; // Blanc
}

void init_palette_G(int palette_G[20])
{
    palette_G[0] = 0x000000; // Noir
    palette_G[1] = 0x003300; // Vert très sombre
    palette_G[2] = 0x006600; // Vert foncé
    palette_G[3] = 0x009900; // Vert intense
    palette_G[4] = 0x00CC00; // Vert vif foncé
    palette_G[5] = 0x00FF00; // Vert pur
    palette_G[6] = 0x4CFF4C; // Vert clair
    palette_G[7] = 0x80FF80; // Vert pâle
    palette_G[8] = 0xA6FFA6; // Vert très pâle
    palette_G[9] = 0xB3FFB3; // Vert clair pâle
    palette_G[10] = 0xCCFFCC; // Vert très clair
    palette_G[11] = 0xE0FFE0; // Vert très pâle
    palette_G[12] = 0xF2FFF2; // Vert presque blanc
    palette_G[13] = 0xE6FFE6; // Très pâle
    palette_G[14] = 0xB3FFB3; // Clair
    palette_G[15] = 0x80FF80; // Très clair
    palette_G[16] = 0x4CFF4C; // Vert clair
    palette_G[17] = 0x00CC00; // Vert vif foncé
    palette_G[18] = 0x009900; // Vert intense
    palette_G[19] = 0xFFFFFF; // Blanc
}

int	*palette_selector(int n)
{
	int	palette_R[20];
	int	palette_G[20];
	int	palette_B[20];
	int	*palettes[3];

	init_palette_R(palette_R);
	init_palette_B(palette_B);
	init_palette_G(palette_G);
	palettes[0] = palette_R;
	palettes[1] = palette_G;
	palettes[2] = palette_B;
	return (palettes[n]);
}
// HSL ?
/* int	*palette_selector(int n) */
/* { */
/* 	int palette_R[20]; */
/* 	int palette_G[20]; */
/* 	int palette_B[20]; */
/* 	int palettes[3]; */
/**/
/* 	palette_R = {0xFF0000, 0xFF4500, 0xFF6347, 0xFF7F00, 0xFFB300, */
/* 		0xFFD700, 0xFFFF00, 0xEEDD82, 0xF0E68C, 0xDAA520, 0xB8860B, 0x9ACD32, */
/* 		0xADFF2F, 0x7FFF00, 0x32CD32, 0x00FF00, 0x00FA9A, 0x20B2AA, 0x5F9EA0, */
/* 		0x4682B4}; */
/* 	palette_G = {0x0000FF, 0x1E90FF, 0x6495ED, 0x4169E1, 0x00008B, */
/* 		0x0000CD, 0x4682B4, 0x5F9EA0, 0xB0C4DE, 0xADD8E6, 0x87CEFA, 0x87CEEB, */
/* 		0x4682B4, 0x5F9EA0, 0x191970, 0x8A2BE2, 0x7B68EE, 0x6A5ACD, 0x8B008B, */
/* 		0x9932CC}; */
/* 	palette_B = {0x00FF00, 0x006400, 0x228B22, 0x32CD32, 0x00FF00, */
/* 		0x7FFF00, 0x9ACD32, 0x6B8E23, 0x556B2F, 0x8FBC8F, 0x2E8B57, 0x3CB371, */
/* 		0x20B2AA, 0xADFF2F, 0x7CFC00, 0x98FB98, 0x00FA9A, 0x00FF7F, 0x00FF00, */
/* 		0x66CDAA}; */
/* 	palettes[] = {palette_R, palette_G, palette_B}; */
/**/
/* 	if (n >= 0 && n < 3) */
/* 		return (palettes[n]); */
/* 	else if (n >= 3) */
/* 		return (palettes[n % 3]); */
/* 	return (palettes[0]); */
/* } */

// A revoir
int	generate_smooth_color(int iteration, double mu, int max_iterations,
		int color_modify, int palette_n)
{
	double	t;
	int		index;
	int		*palette;
	int		palette_size;

	(void)color_modify;
	palette = palette_selector(palette_n);
	palette_size = 20;
	t = (iteration + mu) / max_iterations;
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
