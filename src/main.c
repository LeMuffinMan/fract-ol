/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:18:49 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/19 16:03:02 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../minilibx-linux/mlx.h"
#include <X11/X.h> //checker la doc
#include <errno.h>
#include <stddef.h> //stdlib utilise stddef : plus direct
#include <stdio.h>  //perror
#include <stdlib.h>


//Makefile relink et libft 
	//mettre la libft
   //integrer printf
//rechecker le zoom
//A to double a recheck : il accepte une lettre en fin de string ?
	//securiser les overflow
//revoir la couleur
//relire doc mlx
//revoir les theories maths 
//renommer bien les variables
//virer ce qui n'est pas necessaire
//
//check_inputs.c
 //integrer printf
 //coordonnees par defaut pour Julia ?
 //proteger les long long int overflow
 //revoir les cas d'erreur pour atodble
//
//init.c 
 //revoir et proteger init_win
 //faire une fonction qui free ?
//
//input.c : done 
//
//maths.c
  //voir si on fait des fonction separees pour les calculs ?
  //optimiser sqrt ?
//
//render_fractal.c
 //revoir les fonctions static PARTOUT !
 //voir la doc
 //voir pour les couleurs en union et renommer la fonction

//voir si le Makefile relink comme on veut 


//revoir les exit ici 
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
		mlx_loop_end(f->mlx.mlx); // je capte pas cette fonction
		mlx_destroy_display(f->mlx.mlx);
		free(f->mlx.mlx);
	}
	exit(0); // checker la dif entre exit 1 et exit 0
}

/* presets julia */
/* 0.3 0.5  */
/* –0,038088 0.97 */
/*julia -0.8 0.156*/

int	main(int ac, char **av)
{
	t_data	f;

	init_data(&f);
	check_input(ac, av, &f);
	init_win(&f);
	mlx_hook(f.mlx.win, WIN_X, 0, quit, &f);                   
	mlx_hook(f.mlx.win, KeyRelease, KeyReleaseMask, kb_inputs, &f);
	mlx_mouse_hook(f.mlx.win, mouse_inputs, &f);
	mlx_loop(f.mlx.mlx);
	return (0);
}


