/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:39:54 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/23 18:30:27 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/* #include <stdlib.h> */
#include "../include/fractol.h"
#include <math.h> // a virer

int	julia_dynamic(int x, int y, t_fractal *f)
{
	/* printf("x = %d | y = %d\n", x, y); */
	if (f->fractal_number == 6 || f->fractal_number == 5
		|| f->fractal_number == 4)
	{
		f->mouse_x = (scale(x, -3, +3, 0, WINSIZE_X) * f->tmp_zoom)
			+ f->tmp_shift_x;
		f->mouse_y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->tmp_zoom)
			+ f->tmp_shift_y;
	}
	else
	{
		f->mouse_x = (scale(x, -3, +3, 0, WINSIZE_X) * f->zoom) + f->shift_x;
		f->mouse_y = (scale(y, +3, -3, 0, WINSIZE_Y) * f->zoom) + f->shift_y;
	}
	return (0);
}

int 	wheel(int key, int x, int y, t_fractal *f)
{
	if (key == MOUSE_WHEEL_DOWN) // zoom normal
	{
		f->zoom *= 1.1;
		f->shift_x -= (x - WINSIZE_X / 2.0) * f->zoom / 1000;
		f->shift_y += (y - WINSIZE_Y / 2.0) * f->zoom / 1000;
		return (1);
	}
	else if (key == MOUSE_WHEEL_UP) // zoom normal
	{
		f->zoom *= 0.9;
		f->shift_x += (x - WINSIZE_X / 2.0) * f->zoom / 1000;
		f->shift_y -= (y - WINSIZE_Y / 2.0) * f->zoom / 1000;
		return (1);
	}
	else if (key == MOUSE_WHEEL_CLICK && f->bind_combo == 0) // reset zoom
	{
		f->zoom = 1.0;
		f->shift_x = 0.0;
		f->shift_y = 0.0;
		return (1);
	}
	return (0);
}

// ne pas regenerer une julia
// generer burningship au cub ? tricron multi ?
void 	clicks_combo(int key, t_fractal *f)
{
	if (key == MOUSE_L && f->bind_combo == 1 && f->bind_combo_z == 0) // select julia cx cy
	{
		if (f->fractal_number < 4 || f->fractal_number == 7)
		{
			f->tmp_shift_x = f->shift_x;
			f->tmp_shift_y = f->shift_y;
			f->tmp_zoom = f->zoom;
			f->tmp_fractal_number = f->fractal_number;
			f->shift_x = 0.0;
			f->shift_y = 0.0;
			f->zoom = 1.0;
			if (f->fractal_number == 7)
				// on passe de multibrot a julia de multibrot
				f->fractal_number++;
			else if (f->fractal_number > 0 && f->fractal_number < 4)
				// on passe de mandel / burning / tricorn aux julias
				f->fractal_number += 3;
			printf("c = %f %fi\n", f->mouse_x, f->mouse_y);
		}
		f->j_x = f->mouse_x;
		f->j_y = f->mouse_y;
	}
}

void clicks(int key, int x, int y, t_fractal *f)
{
	if (key == MOUSE_R && f->bind_combo == 0 && f->bind_combo_z == 0) // zoom opti
	{
		f->zoom *= 1.2;
		f->shift_x -= (x - WINSIZE_X / 2.0) * f->zoom / 100;
		f->shift_y += (y - WINSIZE_Y / 2.0) * f->zoom / 100;
	}
	else if (key == MOUSE_L && f->bind_combo == 0 && f->bind_combo_z == 0) // zoom opti
	{
		f->zoom *= 0.8;
		f->shift_x += (x - WINSIZE_X / 2.0) * f->zoom / 100;
		f->shift_y -= (y - WINSIZE_Y / 2.0) * f->zoom / 100;
	}
	clicks_combo(key, f);
}

void animated_zoom_out(int x, int y, t_fractal *f)
{
	f->zooming_out = 0;
		if (f->zoom < 1)
		{
			f->zooming_out = 1;
			f->zoom *= 1.1;
			if (f->zoom > 0.09 && f->zoom < 1)
			{
				f->shift_x -= (x - WINSIZE_X / 2.0) * f->zoom / 1000;
				f->shift_y += (y - WINSIZE_Y / 2.0) * f->zoom / 1000;
				f->shift_x *= 0.99; // Ajuste ce facteur pour ralentir ou accélérer
      	f->shift_y *= 0.99;
      }
      if (f->zoom > 1)
      {
      	f->zoom = 1;
      	/* f->shift_x = 0; */
      	/* f->shift_y = 0; */
      }
			if (f->psyche_switch == 1 && f->psychedelic_colors == 1)
				f->modify_color += f->t;
			iterate_on_pixels(f);
			mlx_do_sync(f->mlx);
		}

}

void animated_zoom_in(t_fractal *f)
{
    double target_zoom = f->zoom / 100000; // Définir un zoom cible très petit
    double speed_factor = 0.02; // Contrôle de la vitesse du zoom
		
		f->zooming_in = 0;
    if (f->zoom > target_zoom)
    {
        f->zooming_in = 1;
        // Calcul d'une interpolation linéaire pour une transition fluide
        f->zoom *= (1 - speed_factor); // Réduction progressive du zoom
				if (f->psyche_switch == 1 && f->psychedelic_colors == 1)
					f->modify_color += f->t;
        // Mettre à jour les pixels et synchroniser l'affichage
        iterate_on_pixels(f);
        mlx_do_sync(f->mlx);

        // Condition de sortie si très proche du zoom cible
        if (fabs(f->zoom - target_zoom) < f->zoom / 100000)
            f->zooming_in = 0;
		{
			/* f->zoom *= 0.99; */
			/* iterate_on_pixels(f); */
			/* mlx_do_sync(f->mlx); */
   /*    if (fabs(f->zoom - target_zoom) < f->zoom / 100000) */
   /*    	break; */
		}
		}
}

void animated_zoom(int key, int x, int y, t_fractal *f)
{
	if (key == MOUSE_R && f->bind_combo_z == 1) 
	{
		f->zooming_in_x = x;
		f->zooming_in_y = y;
		animated_zoom_out(x, y, f);
	}
	/* else if (key == MOUSE_L && f->bind_combo_z == 1) */
	/* { */
 /*    	double initial_zoom = f->zoom;         // Zoom initial */
 /*    	double target_zoom = f->zoom / 100000; // Zoom cible (beaucoup plus petit) */
 /*    	double progress = 0.0;                // Progression de 0.0 à 1.0 */
 /*    	double speed_factor = 0.02;           // Contrôle de la durée totale du zoom */
	/**/
 /*    	while (progress < 1.0) */
 /*    	{ */
 /*        	// Calcul d'un eased_progress avec une courbe sinus */
 /*        	double eased_progress = (1 - cos(progress * pi)) / 2; // Ease-in-out */
	/**/
 /*        	// Interpolation entre initial_zoom et target_zoom */
 /*        	f->zoom = initial_zoom * pow(target_zoom / initial_zoom, eased_progress); */
	/**/
 /*        	// Mettre à jour les pixels et synchroniser l'affichage */
 /*        	iterate_on_pixels(f); */
 /*        	mlx_do_sync(f->mlx); */
	/**/
 /*        	// Augmenter la progression (ralentir en ajustant speed_factor) */
 /*        	progress += speed_factor; */
	/**/
 /*        	// Condition de sortie pour éviter les erreurs de précision flottante */
 /*        	if (fabs(f->zoom - target_zoom) < 0.000001) */
 /*            	break; */
 /*    	} */
	/* } */
	else if (key == MOUSE_L && f->bind_combo_z == 1)
		animated_zoom_in(f);
}

int travel_update(void *param)
{
	t_fractal *f = (t_fractal *)param;

	if (f->traveling == 1)
		travel_between_fractals(f);
	if (f->zooming_out == 1)
		animated_zoom_out(f->zooming_in_x, f->zooming_in_y, f);
	if (f->zooming_in == 1)
		animated_zoom_in(f);
	return (0);
}

void	travel_between_fractals(t_fractal *f)
{
	f->traveling = 1;
	if (f->t > M_PI) //utiliser pi de math.h ?
	{
		f->t = 0;
		f->traveling = 0;
		f->origin = 0;
		return;
	}
	if (f->debug == 1)
		printf("boucle t = %f\nj_x = %f\nj_y = %f\n", f->t, f->j_x, f->j_y);

	/* mlx_clear_window(f->mlx, f->win); */
	f->t += f->tc;
	f->j_x = f->o.x + ((sin(f->t) + 1) * 0.5) * f->d.x; //Demander a erwan pour faire boucler a l'infini
	f->j_y = f->o.y + ((sin(f->t) + 1) * 0.5) * f->d.y;

	if (f->psyche_switch == 1 && f->psychedelic_colors == 1)
		f->modify_color += f->t;

	if (f->debug == 1)
		printf("modify_color = %f\n", f->modify_color);

	iterate_on_pixels(f);
	mlx_do_sync(f->mlx);
	/* f->traveling = 1; */
	/* f->j_x = f->o.x; */
	/* f->j_y = f->o.y; */
	/* while (f->t <= pi) */
	/* { */
	/* 	if (f->debug == 1) */
	/* 		printf("boucle t = %f\nj_x = %f\nj_y = %f\n", f->t, f->j_x, f->j_y); */
	/* 	mlx_clear_window(f->mlx, f->win); */
	/* 	f->t += f->tc; */
	/* 	f->j_x = f->o.x + ((sin(f->t) + 1) * 0.5) * f->d.x; */
	/* 	f->j_y = f->o.y + ((sin(f->t) + 1) * 0.5) * f->d.y; */
	/* 	if (f->psyche_switch == 1 && f->psychedelic_colors == 1) */
	/* 		f->modify_color += f->t; */
	/* 	if (f->debug == 1) */
	/* 		printf("modify_color = %f\n", f->modify_color); */
	/* 	iterate_on_pixels(f); */
	/* 	mlx_do_sync(f->mlx); */
	/* 	f->origin = 0; */
	/* } */
	/* f->t = 0; */
}


/* void  */

int	mouse_inputs(int key, int x, int y, t_fractal *f)
{
	wheel(key, x, y, f);
	clicks(key, x, y, f);
	animated_zoom(key, x, y, f);
	if (key == MOUSE_WHEEL_CLICK && f->bind_combo == 1)
	{
		if (f->origin == 0)
		{
			f->o.x = f->mouse_x;
			f->o.y = f->mouse_y;
			if (f->debug == 1)
			{
				printf("o.x = %f\n", f->o.x);
				printf("o.y = %f\n", f->o.y);
			}
			f->origin = 1;
		}
		else
		{
			f->a.x = f->mouse_x;
			f->a.y = f->mouse_y;
			if (f->debug == 1)
			{
				printf("a.x = %f\n", f->a.x);
				printf("a.y = %f\n", f->a.y);
			}
			f->origin = 0;
			f->d.x = f->a.x - f->o.x;
			f->d.y = f->a.y - f->o.y;
			f->tmp_shift_x = f->shift_x;
			f->tmp_shift_y = f->shift_y;
			f->tmp_zoom = f->zoom;
			f->tmp_fractal_number = f->fractal_number;
			if (f->fractal_number <= 3)
				f->fractal_number = f->fractal_number + 3;
			/* if (f->fractal_number > 3 && f->fractal_number < 7)
				//on veut rester en julia si on est en julia */
			/* 	f->fractal_number = f->fractal_number; */
			else if (f->fractal_number == 7)
				f->fractal_number++;
			f->shift_x = 0.0;
			f->shift_y = 0.0;
			f->zoom = 1.0;
			travel_between_fractals(f);
		}
	}

		iterate_on_pixels(f);
	return (key);
}
