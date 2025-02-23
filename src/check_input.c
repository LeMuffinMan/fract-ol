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
#include "libft.h"

static void	input_error(void)
{
	ft_printf("=========================================\n");
	ft_printf("||          Incorrect input !          ||\n");
	ft_printf("||-------------------------------------||\n");
	ft_printf("||  ./fractol mandelbrot               ||\n");
	ft_printf("||  ./fractol julia <x> <y>            ||\n");
	ft_printf("=========================================\n");
	exit(1);
}

static double	get_double(char *s, int sign, int *max_digits)
{
	int		i;
	double	res1;
	double	res2;
	double	factor;

	factor = 1.0;
	res1 = 0;
	res2 = 0;
	i = 0;
	while (s[i] < '0' || s[i] > '9')
		i++;
	while (s[i] >= '0' && s[i] <= '9' && (*max_digits)-- > 0)
		res1 = res1 * 10 + s[i++] - '0';
	if (s[i++] == '.')
	{
		while (s[i] >= '0' && s[i] <= '9' && (*max_digits)-- > 0)
		{
			res2 = res2 * 10 + s[i++] - '0';
			factor *= 10;
		}
	}
	res1 = (res1 + res2 / factor) * sign;
	return (res1);
}

static double	atodbl(char *s, int *max_digits)
{
	int	i;
	int	dot;
	int	sign;

	sign = 1;
	dot = 0;
	i = skip_spaces(s, &sign, max_digits);
	return (get_double(s, sign, max_digits));
}

static void	get_coords(int ac, char **av, t_data *f, int *check_double)
{
	if (ac == 4)
	{
		if (!check_format(av[2]) || !check_format(av[3]))
			input_error();
		f->julia_constant.x = atodbl(av[2], check_double);
		f->julia_constant.y = atodbl(av[3], check_double);
		if (*check_double == -1)
			input_error();
	}
	else
	{
		f->julia_constant.x = -0.8;
		f->julia_constant.y = 0.156;
	}
}

void	check_input(int ac, char **av, t_data *f)
{
	int	check_double;

	check_double = 15;
	if (ac == 1 || ac > 4)
		input_error();
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0 && ac == 2)
		f->fractal_number = 1;
	else if (ft_strncmp(av[1], "julia", 5) == 0 && (ac == 2 || ac == 4))
	{
		get_coords(ac, av, f, &check_double);
		f->fractal_number = 2;
	}
	else
		input_error();
}
