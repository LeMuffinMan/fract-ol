/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:09:24 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/20 16:23:28 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	if (ch == 0)
	{
		while (*s)
			s++;
		return ((char *) s);
	}
	if (*s == '\0')
		return (NULL);
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char *) s);
		s++;
	}
	if (*s == '\0')
	{
		if (ch == '\0')
			return ((char *)s);
		s = NULL;
	}
	return ((char *)s);
}
