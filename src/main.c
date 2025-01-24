/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:18:49 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/23 18:30:21 by oelleaum         ###   ########lyon.fr   */
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
 * 				tout comme l'ensemble de Mandelbrot, mais il se comporte différemment selon que cc appartient 
 * 				ou non à l'ensemble de Mandelbrot.
 * 				
 * 				Caractère dynamique de l'ensemble de Julia : Si cc appartient à l'ensemble de Mandelbrot 
 * 				(c'est-à-dire que la suite zn=zn−12+czn​=zn−12​+c ne diverge pas quand z0=0z0​=0), 
 * 				alors l'ensemble de Julia associé à cette valeur de cc est connecté et forme une structure "solide" sans trous. 
 * 				Si cc ne fait pas partie de l'ensemble de Mandelbrot, l'ensemble de Julia associé à cette valeur est découpé, 
 * 				constitué de plusieurs composants disjoints.
 *
 * 				en gros : Julia applique la formule de mandelbrot MAIS avec z0 pas forcement = 0 mais n'importe quelle valeur c
 *
 * Burning ship : zn+1 = abs(zn^2) + c avec z0 = 0
 * https://math.stackexchange.com/questions/2322660/what-are-3d-burning-ship-fractals
 * https://robotmoon.com/burning-ship-fractal/
 *
 * Newton : zn+1 = zn - (f(zn) / f`(zn)) / f(z) est un polynome generalement f(z) = z^3 - 1
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

//calcul du complex * scale * zoom

// julia -0.4 0.6

/* to do 
 *
 * // 4 5 6 pour les julias en racourcis
 *
 * // erwan faireboucler a l'infini
 * zoom out animated qui zoom in un coup ?
 *
 * 1 : gestion d'erreurs
 * 		revoir si les coordonees sont niquees 
 * 		penser aux AUTRES cas d'erreur
 *
 * 2 : ranger et subdiviser
 * 	- check_input : a normer
 * 	- color : a normer
 * 	- init : a normer
 * 	- inputs : renomer kb_inputs.c
 * 		- kbinputs : diviser
 * 	- maths 
 * 		-choisir si on garde les deux strats de calcul
 * 	- mouse_inputs 
 * 		-wheel marche pas 
 * 		- diviser
 * 	- render fractal to norm
 * 		- CHANGER ZX POUR ZR ETC
 * 		- essayer d'optimiser les appels aux structs
 *
 * 	- main 
 * 	 	- ranger quit
 * 	 	- revoir l'enchainement
 *
 * 3 : incorporer libft
 * 	- strncmp 
 * 	- printf // cas des floats ?
 * 
 * 4 : Makefile bonus
 * 	- split bonus
 * 	- clean base
 * 
 * 5 : checker la doc
 * 			- hooks
 * 			- couleurs
 * 			- maths : MU !
 *
 *  /// !!! VIRER NOTES.C du GIT !
 * //mettre des fonctions en static
 * */

// choisir un point a click droit
// choisir un point b click droit
//  d.x = a.x - b.x
//  d.y = a.y - b.y
// render la premiere avec le point click droit
// t entre 1 et 0 avec cos et sin
// boucle while t < 1
// 	c.x * t
// 	c.y * t
//  render_fractal(julia)
//

#include "../include/fractol.h"
#include <X11/X.h> //checker la doc
#include <stddef.h> //stdlib utilise stddef : plus direct
#include <stdio.h> //perror 
#include "../minilibx-linux/mlx.h" 
#include <errno.h>
#include <stdlib.h>


int quit(t_fractal *f)
{
	if (!f)
		exit(1);
	if (f->img.img_p)
		mlx_destroy_image(f->mlx, f->img.img_p);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx); //je capte pas cette fonction
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(0); //checker la dif entre exit 1 et exit 0
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

	 /* presets julia */
	  /* 0.3 0.5  */
/* –0,038088 0.97 */

int main(int ac, char **av)
{
	t_fractal f;

	init_fra(&f);
	check_input(ac, av, &f);
	init_win(&f);
	iterate_on_pixels(&f);
	mlx_hook(f.win, WIN_X, 0, quit, &f); // Comment la mixer avec inputs ?
	mlx_hook(f.win, KeyPress, KeyPressMask, kb_inputs, &f); //peut marcher sans le 3eme param ?
	mlx_hook(f.win, KeyRelease, KeyReleaseMask, shift_toggle, &f);
	mlx_mouse_hook(f.win, mouse_inputs, &f);
	//
	//
	/* mlx_mouse_hook(f.win, wheel, &f); // marche pas */

	mlx_hook(f.win, MotionNotify, PointerMotionMask, julia_dynamic, &f);
	/* mlx_hook(f.win, ButtonRelease, ButtonReleaseMask, mouse_inputs, &f); */

	mlx_loop_hook(f.mlx, travel_update, &f);

	mlx_loop(f.mlx);
	
	return (0);
}

