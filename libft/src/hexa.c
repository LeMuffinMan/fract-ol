/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:38:35 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/26 10:51:47 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hexa_len(unsigned int n)
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

int	dec_to_hex(unsigned int n, char format)
{
	int	count;

	count = hexa_len(n);
	if (n >= 16)
	{
		dec_to_hex((n / 16), format);
		dec_to_hex((n % 16), format);
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
			if (format == 'X')
				n = n + 55;
			else
				n = n + 87;
			ft_putchar_fd(n, 1);
		}
	}
	return (count);
}

int	f_hex(unsigned int n, char format)
{
	int	count;

	count = dec_to_hex(n, format);
	return (count);
}
