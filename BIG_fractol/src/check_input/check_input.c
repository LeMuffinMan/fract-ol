/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:40:10 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 19:28:39 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>
#include <stdlib.h>

/* remplacer pritnf !  */
// utiliser strncmp

void	param_error(void)
{
	printf("=========================================\n");
	printf("||          Incorrect input !          ||\n");
	printf("||-------------------------------------||\n");
	printf("||  ./fractol <set_name>               ||\n");
	printf("||  ./fractol julia_mandel <x> <y>     ||\n");
	printf("||                                     ||\n");
	printf("||-----------------SETS----------------||\n");
	printf("||   mandelbrot     |   multibrot      ||\n");
	printf("||   burning_ship   |   tricorn        ||\n");
	printf("||-------------------------------------||\n");
	printf("||   julia_mandel   |   julia_multi    ||\n");
	printf("||   julia_ship     |   julia_tricorn  ||\n");
	printf("=========================================\n");
	exit(1);
}

void	check_julia_input(int ac, char **av, t_fractal *f, int *check_double)
{
	if (ft_strcmp(av[1], "julia_mandel") == 0 && (ac == 2 || ac == 4))
	{
		get_coords(ac, av, f, check_double);
		f->fractal_number = 4;
	}
	else if (ft_strcmp(av[1], "julia_ship") == 0 && (ac == 2 || ac == 4))
	{
		get_coords(ac, av, f, check_double);
		f->fractal_number = 5;
	}
	else if (ft_strcmp(av[1], "julia_tricorn") == 0 && (ac == 2 || ac == 4))
	{
		get_coords(ac, av, f, check_double);
		f->fractal_number = 6;
	}
	else if (ft_strcmp(av[1], "julia_multi") == 0 && (ac == 2 || ac == 4))
	{
		get_coords(ac, av, f, check_double);
		f->power = 3;
		f->fractal_number = 8;
	}
	else
		param_error();
}

void	check_input(int ac, char **av, t_fractal *f)
{
	int	check_double;

	check_double = 15;
	if (ac == 1 || ac > 4)
		param_error();
	if (ft_strcmp(av[1], "mandelbrot") == 0 && ac == 2)
		f->fractal_number = 1;
	else if (ft_strcmp(av[1], "burning_ship") == 0 && ac == 2)
		f->fractal_number = 2;
	else if (ft_strcmp(av[1], "tricorn") == 0 && ac == 2)
		f->fractal_number = 4;
	else if (ft_strcmp(av[1], "multibrot") == 0 && ac == 2)
	{
		f->power = 3;
		f->fractal_number = 7;
	}
	else
		check_julia_input(ac, av, f, &check_double);
}
