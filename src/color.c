//HEADER 

//6 fonctions :
//trier et garder ce qu'on veut

#include "../include/fractol.h"
#include <math.h>

void colorize_pixel(int x, int y, t_img *img, int color) //degrader a gerer ic.y ?
//je capte pas ce que je fais la 
{
	int offset;

	offset = (y * img->line_len) + (x * (img->bpp));
	*(unsigned int *)(img->pixels + offset) = color;
}

/**
 * Interpolation linéaire entre deux couleurs
 */
int interpolate_color(int color1, int color2, double t)
{
    int r = ((1 - t) * ((color1 >> 16) & 0xFF)) + (t * ((color2 >> 16) & 0xFF));
    int g = ((1 - t) * ((color1 >> 8) & 0xFF)) + (t * ((color2 >> 8) & 0xFF));
    int b = ((1 - t) * (color1 & 0xFF)) + (t * (color2 & 0xFF));
    return (r << 16) | (g << 8) | b;
}

/**
 * Palette prédéfinie
 */
int palette[] = {
    /* 0xFF0000, // Rouge */
    /* 0xFF7F00, // Orange */
    /* 0xFFFF00 // Jaune */
    0x00FF00, // Vert
    0x0000FF, // Bleu
    0x4B0082, // Indigo
    0x8B00FF  // Violet
};

/**
 * Générer une couleur psychédélique avec une palette et interpolation
 */
int generate_psychedelic_color(int iteration, int max_iterations)
{
    double t = (double)iteration / max_iterations;
    int palette_size = sizeof(palette) / sizeof(int);

    // Couleurs de la palette en fonction des itérations
    int color1 = palette[iteration % palette_size];
    int color2 = palette[(iteration + 1) % palette_size];

    // Appliquer une interpolation linéaire pour des transitions douces
    return interpolate_color(color1, color2, fmod(t * palette_size, 1.0));
}

/**
 * Générer une couleur cyclique avec des fonctions sinus/cosinus
 */
int generate_cyclic_color(int iteration, int max_iterations)
{
    double t = (double)iteration / max_iterations;
    int r = (int)(128 * (1 + sin(6.28318 * t)));         // Sinus pour des transitions douces
    int g = (int)(128 * (1 + sin(6.28318 * t + 2.0)));   // Décalage de phase
    int b = (int)(128 * (1 + sin(6.28318 * t + 4.0)));   // Décalage de phase
    return (r << 16) | (g << 8) | b;
}

/**
 * Mélanger les deux approches pour un effet unique
 */
int generate_combined_color(int iteration, int max_iterations)
{
    int psychedelic_color = generate_psychedelic_color(iteration, max_iterations);
    int cyclic_color = generate_cyclic_color(iteration, max_iterations);

    // Mélange des deux couleurs (50% de chaque)
    return interpolate_color(psychedelic_color, cyclic_color, 0.5);
}

//A TESTER 
/* int generate_coordinate_based_color(t_complex z, int max_iterations) */
/* { */
/*     double norm = sqrt(z.x * z.x + z.y * z.y); */
/*     int r = (int)(128 * (1 + sin(norm * 6.28318))); */
/*     int g = (int)(128 * (1 + sin(norm * 6.28318 + 2.0))); */
/*     int b = (int)(128 * (1 + sin(norm * 6.28318 + 4.0))); */
/*     return (r << 16) | (g << 8) | b; */
/* } */




int generate_smooth_color(int iteration, double mu, int max_iterations)
{
    double t = (iteration + 1 - mu) / max_iterations; // Fraction lissée
    int palette_size = sizeof(palette) / sizeof(int);

    int color1 = palette[(int)(t * palette_size) % palette_size];
    int color2 = palette[((int)(t * palette_size) + 1) % palette_size];

    return interpolate_color(color1, color2, fmod(t * palette_size, 1.0));
}
