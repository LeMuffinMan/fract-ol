/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:40:10 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/22 10:51:12 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft/include/libft.h"
#include "../../include_bonus/fractol_bonus.h"
#include <stdlib.h>

void	param_error(void)
{
	ft_printf("=========================================\n");
	ft_printf("||          Incorrect input !          ||\n");
	ft_printf("||-------------------------------------||\n");
	ft_printf("||  ./fractol <set_name>               ||\n");
	ft_printf("||  ./fractol julia_mandel <x> <y>     ||\n");
	ft_printf("||                                     ||\n");
	ft_printf("||-----------------SETS----------------||\n");
	ft_printf("||   mandelbrot     |   multibrot      ||\n");
	ft_printf("||   burning_ship   |   tricorn        ||\n");
	ft_printf("||-------------------------------------||\n");
	ft_printf("||   julia_mandel   |   julia_multi    ||\n");
	ft_printf("||   julia_ship     |   julia_tricorn  ||\n");
	ft_printf("=========================================\n");
	exit(1);
}

void	check_julia_input(int ac, char **av, t_data *f, int *check_double)
{
	if (ft_strncmp(av[1], "julia_mandel", 12) == 0 && (ac == 2 || ac == 4))
	{
		get_coords(ac, av, f, check_double);
		f->fractal_number = 4;
	}
	else if (ft_strncmp(av[1], "julia_ship", 10) == 0 && (ac == 2 || ac == 4))
	{
		get_coords(ac, av, f, check_double);
		f->fractal_number = 5;
	}
	else if (ft_strncmp(av[1], "julia_tricorn", 13) == 0 && (ac == 2
			|| ac == 4))
	{
		get_coords(ac, av, f, check_double);
		f->fractal_number = 6;
	}
	else if (ft_strncmp(av[1], "julia_multi", 11) == 0 && (ac == 2 || ac == 4))
	{
		get_coords(ac, av, f, check_double);
		f->power = 3;
		f->fractal_number = 8;
	}
	else
		param_error();
}

void	check_input(int ac, char **av, t_data *f)
{
	int	check_double;

	check_double = 15;
	if (ac == 1 || ac > 4)
		param_error();
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0 && ac == 2)
		f->fractal_number = 1;
	else if (ft_strncmp(av[1], "burning_ship", 12) == 0 && ac == 2)
		f->fractal_number = 2;
	else if (ft_strncmp(av[1], "tricorn", 7) == 0 && ac == 2)
		f->fractal_number = 4;
	else if (ft_strncmp(av[1], "multibrot", 9) == 0 && ac == 2)
	{
		f->power = 3;
		f->fractal_number = 7;
	}
	else
		check_julia_input(ac, av, f, &check_double);
}
