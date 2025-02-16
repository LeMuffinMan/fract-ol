/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:23:23 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/20 16:22:53 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;

	ch = (unsigned char) c;
	str = (unsigned char *) s;
	while (n > 0)
	{
		if (*str == ch)
			return (str);
		str++;
		n--;
	}
	if (n == 0)
		str = NULL;
	return (str);
}
