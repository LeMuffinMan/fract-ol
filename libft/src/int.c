/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:39:36 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/26 10:12:13 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_uint(unsigned int n)
{
	if (n >= 10)
	{
		print_uint(n / 10);
		print_uint(n % 10);
	}
	else
	{
		if (n < 10)
		{
			n = n + '0';
			ft_putchar_fd(n, 1);
		}
		else
		{
			n = n + 87;
			ft_putchar_fd(n, 1);
		}
	}
}

int	f_uint(unsigned int n)
{
	int	count;

	count = 0;
	print_uint(n);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

int	f_int(int n)
{
	int	count;

	count = 0;
	ft_putnbr_fd(n, 1);
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}
