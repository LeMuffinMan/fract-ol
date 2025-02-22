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
#include "libft.h"

// inline ici ?

int	skip_spaces(char *s, int *sign, int *max_digits)
{
	int	i;

	i = 0;
	while (s[i] <= ' ' || s[i] == '+')
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

static int	check_dot(char *s, int i)
{
	if (s[i - 1] && s[i + 1])
		return (ft_isdigit(s[i - 1]) && ft_isdigit(s[i + 1]));
	return (0);
}

static int	check_invalid_char(char c)
{
	return (!(ft_isdigit(c) || c == '-' || c == '+' || c == '.'));
}

int	check_format(char *s)
{
	int	i;
	int	digits;
	int	dot;

	i = 0;
	digits = 0;
	dot = 0;
	while (s[i])
	{
		if (check_invalid_char(s[i]))
			return (0);
		if (s[i] == '.' && !check_dot(s, i))
			return (0);
		if (s[i] == '.')
			dot++;
		if (ft_isdigit(s[i]))
			digits++;
		i++;
	}
	if ((dot == 0 && digits > 0) || (dot == 1 && digits > 1))
		return (1);
	return (0);
}
