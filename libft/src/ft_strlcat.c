/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:52:36 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/20 16:23:54 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_dest;
	size_t	size_src;

	size_dest = ft_strlen(dst);
	size_src = ft_strlen(src);
	i = size_dest;
	if (size == 0)
		return (size_src);
	if (size_dest >= size)
		return (size + size_src);
	while (src[i - size_dest] != '\0' && i < size - 1)
	{
		dst[i] = src[i - size_dest];
		i++;
	}
	dst[i] = '\0';
	return (size_dest + size_src);
}
