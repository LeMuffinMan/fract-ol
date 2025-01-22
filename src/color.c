// HEADER

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

//generer plusieurs palettes
    //mettre la palette dans une fonction
    //modifier dynamiquement 
    //varier jeux de palettes
int generate_smooth_color(int iteration, double mu, int max_iterations, int color_modify)
{
    int palette[] = { //la mettre dans une struct et proposer 3 variantes ?
    0xFF0000, // Rouge vif
    0xFF4500, // Orange rouge
    0xFF6347, // Rouge tomate
    0xFF7F00, // Orange
    0xFFB300, // Orange clair
    0xFFD700, // Doré brillant
    0xFFFF00, // Jaune vif
    0xEEDD82, // Jaune pâle
    0xF0E68C, // Kaki clair
    0xDAA520, // Doré foncé
    0xB8860B, // Or brunâtre
    0x9ACD32, // Vert jaunâtre (Chartreuse)
    0xADFF2F, // Vert clair (Vert printemps)
    0x7FFF00, // Vert gazon
    0x32CD32, // Vert lime
    0x00FF00, // Vert pur
    0x00FA9A, // Vert menthe
    0x20B2AA, // Vert sarcelle clair
    0x5F9EA0, // Bleu-gris
    0x4682B4  // Bleu acier
  	};
    int palette_size = sizeof(palette) / sizeof(int); //a revoir
    double t = (iteration + mu  + color_modify) / max_iterations; // Fraction lissée
    int index = (int)(t * palette_size) % palette_size; // overkill : je connais la palette sixe
    return palette[index];
}
/**
 * Interpolation linéaire entre deux couleurs
 */
/* int	interpolate_color(int color1, int color2, double t) */
/* { */
/* 	int	r; */
/* 	int	g; */
/* 	int	b; */
/**/
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
/* 		 0x00FF00, // Vert */ 
/* 		 0x0000FF, // Bleu */ 
/* 		 0x4B0082, // Indigo */ 
/* 		 0x8B00FF  // Violet */ 
/* 	}; */
/* 	double t = (iteration + 1 - mu) / max_iterations; // Fraction lissée */
/* 	palette_size = sizeof(palette) / sizeof(int); */
/* 	color1 = palette[(int)(t * palette_size) % palette_size]; */
/* 	color2 = palette[((int)(t * palette_size) + 1) % palette_size]; */
/* 	return (interpolate_color(color1, color2, fmod(t * palette_size, 1.0))); */
/* } */
