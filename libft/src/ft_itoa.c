/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:41:00 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/21 15:07:48 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_digits(int n)
{
	int	digits;

	if (n <= 0)
		digits = 1;
	else
		digits = 0;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char			*s;
	int				digits;
	unsigned int	tmp;

	digits = get_digits(n);
	s = malloc(sizeof(char) * digits + 1);
	if (s == NULL)
		return (NULL);
	s[digits] = '\0';
	if (n < 0)
		tmp = -n;
	else
		tmp = n;
	while (digits > 0)
	{
		digits--;
		s[digits] = (tmp % 10) + '0';
		tmp /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
