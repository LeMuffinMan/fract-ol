/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:53:14 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/20 16:23:00 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*sr;
	unsigned char	*des;

	sr = (unsigned char *) src;
	des = (unsigned char *) dest;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n > 0)
	{
		*des = *sr;
		des++;
		sr++;
		n--;
	}
	return (dest);
}
