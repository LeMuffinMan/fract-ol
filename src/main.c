/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:18:49 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/18 17:11:29 by oelleaum         ###   ########lyon.fr   */
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

/* to do 
 *
 * Mettre la libft
 * 	printf
 * 	ft_strcmp
 *
 * Zoom sous la souris
 * 	Florent
 *
 * Ac Av
 * 	julia x  y
 * 		atodbl
 * 		julia un seul param ?
 * 	Gestion d'erreur 
 * 		perror ?
 * 
 * init.c 
 * 	reorganiser 
 *
 * color.c
 * 	trier et garder ce qu'on veut 
 *
 * inputs.c 
 * 	switch color
 * 	switch renderer ?
 * 		julia from mandel
 * 	rendre zoom moins laggy
 *
 * render_fractal.c
 *  racourcir set_complexes
 * 	reorganiser si 6 fonctions ? 
 * 	tricorn a fix ou virer 
 * 	passer les zx en zr et zy en zi
 *
 * main.c 
 * 		ranger quit
 * 		virer strcmp
 *
 * checker la doc
 * 			- hooks
 * 			- couleurs
 * 
 * Makefile bonus
 * 	split bonus
 * 	clean base
 *
 * revoir le main et l'enchainement des fonctions 
 * 
 * */

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


int main(int ac, char **av)
{
	t_fractal f;
	printf("av[1] = %s | cmp = %d\n", av[1], ft_strcmp(av[1], "julia"));

	init_fra(&f);
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "mandelbrot") == 0)
		{
			/* init_mandelbrot(&f); */
			f.fractal_number = 1;
			printf("mandelbrot_f\n");
		}
		else if (ft_strcmp(av[1], "burning_ship") == 0)
		{
			f.fractal_number = 3;
			printf("burning_ship\n");
		}	
		else if (ft_strcmp(av[1], "tricorn") == 0)
		{
			f.fractal_number = 4;
			printf("tricorn\n");
		}
		else if (ft_strcmp(av[1], "julia") == 0)
		{
			f.fractal_number = 2;
			printf("julia\n");
		}
	}
	/* else if (ac == 2 && ft_strcmp(av[1], "julia") == 0) */
	/* { */
	/* 	//difference entre julia avec et sans param ? */
	/* 	f.fractal_number = 2; */
		/* f.j_x = atodbl(av[2]); //todo */
		/* f.j_y = atodbl(av[3]); //todo */
	/* 	printf("julia\n"); */
	/* } */
	else // a revoir 
	{
		printf("ERROR : type 'mandelbrot, burning_ship, tricorn or julia with or without c.r and c.i\n");
	}
	init_win(&f);
	iterate_on_pixels(&f);
	mlx_hook(f.win, WIN_X, 0, quit, &f); // Comment la mixer avec inputs ?
	mlx_hook(f.win, KeyPress, KeyPressMask, kb_inputs, &f); //peut marcher sans le 3eme param ?
	mlx_mouse_hook(f.win, mouse_inputs, &f);
	mlx_hook(f.win, MotionNotify, PointerMotionMask, julia_dynamic, &f);
	/* mlx_hook(f.win, ButtonRelease, ButtonReleaseMask, mouse_inputs, &f); */

	mlx_loop(f.mlx);
	
	return (0);
}

