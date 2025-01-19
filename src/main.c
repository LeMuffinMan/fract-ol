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
 * Makefile relink sur le .h 
 * Ac Av
 * Julia 
 * degrade plus smooth
 * ranger et renommer fonctions
 * regrouper et optimiser
 * checker la doc
 * 			- hooks
 * 			- couleurs
 * revoir le main et l'enchainement des fonctions 
 * */

#include "../include/fractol.h"
#include <X11/X.h> //checker la doc
#include <stddef.h> //stdlib utilise stddef : plus direct
#include <stdio.h> //perror 
#include "../minilibx-linux/mlx.h" 
#include <errno.h>
#include <stdlib.h>

int init_win(t_fractal *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		return (-1);
	f->win = mlx_new_window(f->mlx, WINSIZE, WINSIZE, "Fractol"); //changer selon l'input le nom de la fenetre
	f->img.img_p = mlx_new_image(f->mlx, WINSIZE, WINSIZE);
	f->img.pixels=mlx_get_data_addr(f->img.img_p, &f->img.bpp, &f->img.line_len, &f->img.endian);
	f->img.bpp /= 8; //conseil pour afficher 4 pixels d'un coup ?
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1.0;
	return (0);
}

int init_mandelbrot(t_fractal *f)
{
	f->escape_value = 4; // pour mandelbrot : hypothenus et pythagore
	f->max_iterations = 10;

	return (0);
}

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

int mouse_inputs(int key, int x, int y, t_fractal *f)
{
    double mouse_re, mouse_im;

    // Conversion des coordonnées de la souris en coordonnées réelles de l'image
    mouse_re = (x - WINSIZE / 2.0) / f->zoom + f->shift_x;
    mouse_im = (y - WINSIZE / 2.0) / f->zoom + f->shift_y;

    if (key == MOUSE_WHEEL_DOWN)
    {
        f->zoom *= 1.1;
    }
    else if (key == MOUSE_WHEEL_UP)
    {
        f->zoom *= 0.9;
    }

    // Calcul du nouveau décalage basé sur la position de la souris
    f->shift_x = (x - WINSIZE / 2.0) / f->zoom - mouse_re;
    f->shift_y = (y - WINSIZE / 2.0) / f->zoom - mouse_im;

    iterate_on_pixels(f); // Recalcul des pixels avec la nouvelle valeur de zoom
    return (key);
}

/* int	mouse_inputs(int key, int x, int y, t_fractal *f) */
/* { */
/* 	(void)x; //Zoom sous la souris ? */
/* 	(void)y; */
/* 	if (key == MOUSE_WHEEL_DOWN) */
/* 		f->zoom *= 1.1; */
/* 	else if (key == MOUSE_WHEEL_UP) */
/* 		f->zoom *= 0.9; */
/* 	iterate_on_pixels(f); */
/* 	return (key); */
/* } */

int kb_inputs(int key, t_fractal *f)
{
	if (key == WIN_X || key == ESC)
		quit(f);
	else if (key == RIGHT)
		f->shift_x += (0.2 * f->zoom);
	else if (key == LEFT)
		f->shift_x -= (0.2 * f->zoom);
	else if (key == DOWN)
		f->shift_y -= (0.2 * f->zoom);
	else if (key == UP)
		f->shift_y += (0.2 * f->zoom);
	else if (key == PLUS)
	{
		f->max_iterations += 1;
		printf("max_iterations = %d\n", f->max_iterations); //A VIRER !!!
	}
	else if (key == MINUS)
	{
		f->max_iterations -= 1;
		printf("max_iterations = %d\n", f->max_iterations);
	}
	iterate_on_pixels(f);
	return (0);
}

void 	iterate_on_pixels(t_fractal *f)
{
	int x;
	int y;

	y = 0;
	while (y < WINSIZE)
	{
		x = 0;
		while (x < WINSIZE)
		{
			mandelbrot_f(x, y, f);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_p, 0, 0);
}

int main(void)
{
	t_fractal f;

	init_win(&f);
	init_mandelbrot(&f);
	iterate_on_pixels(&f);
	mlx_hook(f.win, WIN_X, 0, quit, &f); // Comment la mixer avec inputs ?
	mlx_hook(f.win, KeyPress, KeyPressMask, kb_inputs, &f); //peut marcher sans le 3eme param ?
	mlx_mouse_hook(f.win, mouse_inputs, &f);
	/* mlx_hook(f.win, ButtonRelease, ButtonReleaseMask, mouse_inputs, &f); */

	mlx_loop(f.mlx);
	
	return (0);
}




//faire un scale pour les couleurs plutot que reprendre scale
/* double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max) //a reecrire */
/* { */
/* 	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min; */
/* } */
/**/
/* void colorize_pixel(int x, int y, t_img *img, int color) //degrader a gerer ici ? */
/* //je capte pas ce que je fais la  */
/* { */
/* 	int offset; */
/**/
/* 	offset = (y * img->line_len) + (x * (img->bpp)); */
/* 	*(unsigned int *)(img->pixels + offset) = color; */
/* } */
/**/
/* void 	iterate_on_pixels(t_fractal *f) */
/* { */
/* 	int x; */
/* 	int y; */
/**/
/* 	y = 0; */
/* 	while (y < WINSIZE) */
/* 	{ */
/* 		x = 0; */
/* 		while (x < WINSIZE) */
/* 		{ */
/* 			mandelbrot_f(x, y, f); */
/* 			x++; */
/* 		} */
/* 		y++; */
/* 	} */
/* 	mlx_put_image_to_window(f->mlx, f->win, f->img.img_p, 0, 0); */
/* } */
/**/
/**/
/* int	main(void) */
/* { */
/* 	t_fractal	f; */
/**/
/* 	init(&f); */
/* 	iterate_on_pixels(&f);  */
/* 	mlx_hook(f.win, WIN_X, 0, quit_and_free, &f); //a mixer avec inputs  */
/* 	mlx_hook(f.win, KeyRelease, KeyReleaseMask, iterations_inputs, &f); */
/* 	mlx_hook(f.win, KeyPress, KeyPressMask, move_inputs, &f); */
/* 	mlx_hook(f.win, KeyPress, KeyPressMask, quit_inputs, &f); // mixer ces deux qui sont les memes ? */
/* 	mlx_hook(f.win, ButtonRelease, ButtonReleaseMask, zoom_inputs, &f); */
/* 	mlx_hook(f.win, DestroyNotifyMask, StructureNotifyMask, close_handle, f); */ 
/* 	Comment fermer la fenetre avec la croix sans utiliser mlx_hook ? */ 
/* 	mlx_key_hook(f.win, inputs, &f); */ 
/* 	mlx_mouse_hook(fra.win, mouse_wheel_events, &fra); */ 
/* 	mlx_loop(f.mlx); */
/* 	17 = fermer avec la croix */ 
/* 	x mask == filtre permet de programmer un racourci plus complique */ 
/* 	return (0); */
/* } */
