/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:44:30 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/20 16:23:02 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*des;
	unsigned char	*sr;

	des = dest;
	sr = (unsigned char *) src;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (des < sr)
	{
		while (n--)
			*des++ = *sr++;
	}
	else
	{
		des += n;
		sr += n;
		while (n--)
		{
			des--;
			sr--;
			*des = *sr;
		}
	}
	return (dest);
}
