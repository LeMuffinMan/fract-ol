/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:36:30 by oelleaum          #+#    #+#             */
/*   Updated: 2025/01/28 15:44:05 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	skip_spaces(char *s, int *sign, int *max_digits)
{
	int	i;

	i = 0;
	while (s[i] <= 32 || s[i] == '+')
		i++;
	if (s[i] == '-')
	{
		if (*sign == 1)
			*sign = -1;
		else
			(*max_digits = -1);
		i++;
	}
	return (i);
}

double	get_double(char *s, int sign, int *max_digits)
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

double	atodbl(char *s, int *max_digits)
{
	int	i;
	int	dot;
	int	sign;

	sign = 1;
	dot = 0;
	i = skip_spaces(s, &sign, max_digits);
	while (s[i++])
	{
		if (s[i] < '0' && s[i] > '9' && s[i] != '.' && s[i] != '+'
			&& s[i] != '-')
			*max_digits = -1;
		if (s[i] == '.')
		{
			if (dot > 0 || s[i - 1] > '9' || s[i - 1] < '0' || s[i + 1] == '\0')
				*max_digits = -1;
			else
				dot++;
		}
	}
	if (*max_digits >= 0)
		return (get_double(s, sign, max_digits));
	return (0.0);
}

void	get_coords(int ac, char **av, t_fractal *f, int *check_double)
{
	if (ac == 4)
	{
		f->julia_constant.x = atodbl(av[2], check_double);
		f->julia_constant.y = atodbl(av[3], check_double);
		if (*check_double == -1)
			param_error();
	}
}
