/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:03:18 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/26 09:48:04 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				sign;
	char			c;
	long int		nb;

	nb = n;
	c = '0';
	sign = -1;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= sign;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		c = (nb % 10) + '0';
		write(fd, &c, 1);
	}
	else
	{
		c = nb + '0';
		write(fd, &c, 1);
	}
}
