/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:29:42 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/26 10:52:52 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ptr_len(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

int	ptr_to_hex(unsigned long long n)
{
	int	count;

	count = ptr_len(n);
	if (n >= 16)
	{
		ptr_to_hex((n / 16));
		ptr_to_hex((n % 16));
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
	return (count);
}

int	f_ptr(unsigned long long p)
{
	int	count;

	count = 0;
	if (p != 0)
	{
		count += 2;
		write(1, "0x", 2);
	}
	else
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += ptr_to_hex(p);
	return (count);
}
