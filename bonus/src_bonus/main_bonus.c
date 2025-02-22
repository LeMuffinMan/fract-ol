/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:18:49 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/22 10:03:12 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*
 * Mandelbrot : z0 = 0
 * 							zn+1 = zn^2 + c
 *
 * 							z = resultat de l'addition d'un r et d'un i
 * 							c = i
 * 							chaque iteration : z = z^2 + c
 *
 * Julia : meme formule mais c n'est pas un imaginaire
 * 				c est choisi comme un point specifique du plan complexe

					* 				=> c'est une famille de fractales qui depend du parametre c : position du curseur ?
 * 				https://mandelbrotandco.com/en.hub169.html?set=Julia
 *

					* 				Dépendance de l'ensemble de Julia sur c : L'ensemble de Julia dépend de la valeur de cc,
 * 				tout comme l'ensemble de Mandelbrot,
					mais il se comporte différemment selon que cc appartient
 * 				ou non à l'ensemble de Mandelbrot.
 *

					* 				Caractère dynamique de l'ensemble de Julia : Si cc appartient à l'ensemble de Mandelbrot

					* 				(c'est-à-dire que la suite zn=zn−12+czn​=zn−12​+c ne diverge pas quand z0=0z0​=0),

					* 				alors l'ensemble de Julia associé à cette valeur de cc est connecté et forme une structure "solide" sans trous.
 * 				Si cc ne fait pas partie de l'ensemble de Mandelbrot,
					l'ensemble de Julia associé à cette valeur est découpé,
 * 				constitué de plusieurs composants disjoints.
 *

					* 				en gros : Julia applique la formule de mandelbrot MAIS avec z0 pas forcement = 0 mais n'importe quelle valeur c
 *
 * Burning ship : zn+1 = abs(zn^2) + c avec z0 = 0

	* https://math.stackexchange.com/questions/2322660/what-are-3d-burning-ship-fractals
 * https://robotmoon.com/burning-ship-fractal/
 *
 * Newton : zn+1 = zn - (f(zn) / f`(zn))
	/ f(z) est un polynome generalement f(z) = z^3 - 1
 * */

/*
 * General formula to square a complex number
 *
 * (x_real + y_imaginary)^2
 *
 * (x + yi) * (x + yi)
 *
 * x^2 + xyi + xyi + y^2*i^2     / i^2 = -1 /
 * x^2 + 2xyi - y^2
 * (x^2 - y^2) + (2xyi)
 *  reel(x axis) 	imaginary(y axis)
 *
 * */

// calcul du complex * scale * zoom

// julia -0.4 0.6

/* to do
 *
 *
 *  CLEANING :
 *  	- animations/ statics ?
 *  	- check_input/ statics ?
 *  		- mettre libft : strncmp
 *  		- mettre a jour printf pour floats
 *  	- color
		*  	- color.c
		*  		- recaser colorize_pixel dans un fichier qui gere les fct minilibx ?
		*  		- recaser generate_smooth_color
		*  		- revoir les includes du color
		*  	- color_switch.c
		*  		- supprimer les switchs clavier ?
		*  		- si non : static !
		*  	- switch_palette.c
		*  		- reunir avec les switchs clavier ?
 *  	- init : reranger init_utils ?
 *  		- init.c DONE
 *  		- init_palette.c DONE
 *    		- init_utils_1.c DONE
 *    		- init_utils_2.c
 *    			- verifier la protection de init_win
 *    		- kb_inputs
 *    			- kb_animations.c
 *    				- a regrouper ? 2 fct
 *    			- kb_inputs.c DONE
 *    		- kb_julia.c
 *    			- renommer le fichier
 *    		- kb_pav_num.c
 *    			- regrouper les 2 fcts ?
 *    		- kb_switch.c DONE
 *    	- mouse_inputs : regrouper et reorganiser
 *    		- mouse_inputs.c
 *    			- printf a remplacer
 *    		- wheel_combo.c DONE
 *    		- wheel_zoom.c done
 *    	- calculate_fractal.c
 *    		- est-ce qu'on utlise pow ou notre propre fonction ?
 *    	- maths.c
 *    		- reecrire scale pour qu'elle ne prenne que 4 arguments
 *    	- render_fractal.c
 *    		- printf a virer
			- fractol.h
				- a normer
				- combiner WIN_X et WIN_Y
 *
 *
 * REvoir l'entrteee tricron !!!
 *
 * 	Pierre leaks finding :
 * 		des variable non init
 * 		kb input : non init pour un raccourci
 * 			faire le menage dans tous les raccourcis
 *
 *  pour le scaling d'iterations ET pour le plafond de TOUS les zooms :
 *  	f->zoom = 0.00000000000000215778
 *
 * 1 : gestion d'erreurs
 *  - coordonnees rondes renvoient une erreur ? 0.4 0
 * 		penser aux AUTRES cas d'erreur
 *
 * 2 : revoir tout le .h
 * 	- longueur max pour une structure ?
 *
 * 2 : ranger et subdiviser
 * 	- check_input : a normer
 * 	- color : a normer
 * 	- init : a normer
 * 		- a rediviser en fonction du .h
 * 	- kbinputs :
 * 		- diviser
 * 		- normer
 * 	- maths
 * 		-choisir si on garde les deux strats de calcul
 * 	- mouse_inputs
 * 		- diviser
 * 	- render fractal to norm
 * 		- CHANGER ZX POUR ZR ETC
 * 		- essayer d'optimiser les appels aux structs
 *
 * 	- main
 * 			- ranger quit
 * 			- revoir l'enchainement
 *
 * 3 : incorporer libft
 * 	- strncmp
 * 	- printf // cas des floats ?
 *
 * 4 : Makefile bonus
 * 	- ATTENTION A LA COMPILE AVEC LIBFT !
 * 	- split bonus
 * 	- clean base
 *
 * 5 : checker la doc
 * 			- hooks
 * 			- couleurs
 * 			- maths : MU ! e
 * 			- bitshift union
 * 			- sin et anim erwan
 *
 *  /// !!! VIRER NOTES.C du GIT !
 * //mettre des fonctions en static
 * */

/* TODO
 *
 * Doc :
 * 	MLX
 * 	X11
 * 	maths fractales
 *
 * Reprendre les noms de variables de la manda
 * integrer les protections ajoutees au manda
 *
 * Ajouter le mode psyche +
 *
 *
 * Optimiser les ops
 *
 * */

#include "../../minilibx-linux/mlx.h"
#include "../include_bonus/fractol_bonus.h"
#include <X11/X.h> //checker la doc
#include <errno.h>
#include <stddef.h> //stdlib utilise stddef : plus direct
#include <stdio.h>  //perror
#include <stdlib.h>

int	quit(t_data *f)
{
	if (!f)
		exit(1);
	if (f->mlx.img.img_p)
		mlx_destroy_image(f->mlx.mlx, f->mlx.img.img_p);
	if (f->mlx.win)
		mlx_destroy_window(f->mlx.mlx, f->mlx.win);
	if (f->mlx.mlx)
	{
		mlx_loop_end(f->mlx.mlx);
		mlx_destroy_display(f->mlx.mlx);
		free(f->mlx.mlx);
	}
	exit(0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* presets julia */
/* 0.3 0.5  */
/* –0,038088 0.97 */

int	main(int ac, char **av)
{
	t_data	f;

	init_data(&f);
	check_input(ac, av, &f);
	init_win(&f);
	palette_init(&f.palette);
	iterate_on_pixels(&f);
	mlx_hook(f.mlx.win, WIN_X, 0, quit, &f);
	mlx_hook(f.mlx.win, KeyPress, KeyPressMask, kb_inputs, &f);
	mlx_hook(f.mlx.win, KeyRelease, KeyReleaseMask, shift_toggle, &f);
	mlx_mouse_hook(f.mlx.win, mouse_inputs, &f);
	mlx_hook(f.mlx.win, MotionNotify, PointerMotionMask, get_mouse_coords, &f);
	mlx_loop_hook(f.mlx.mlx, update_animations, &f);
	mlx_loop(f.mlx.mlx);
	return (0);
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
/* 	int	PALETTE_SIZE; */
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
/* 	PALETTE_SIZE = sizeof(palette) / sizeof(int); */
/* 	color1 = palette[(int)(t * PALETTE_SIZE) % PALETTE_SIZE]; */
/* 	color2 = palette[((int)(t * PALETTE_SIZE) + 1) % PALETTE_SIZE]; */
/* 	return (interpolate_color(color1, color2, fmod(t * PALETTE_SIZE, 1.0))); */
/* } */

/* colors.r = (char)(9 * (1 - t) * t * t * t * t * 255); */
/* colors.g = (char)(15 * (1 - t) * (1 - t) * t * t * 255); */
/* colors.b = (char)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255); */
