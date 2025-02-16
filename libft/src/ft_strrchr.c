/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:09:24 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/20 16:24:41 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	ch;

	ch = (unsigned char) c;
	str = (char *) s;
	i = 0;
	while (str[i])
		i++;
	while (str[i] != ch && i >= 0)
		i--;
	if (i < 0)
	{
		str = 0;
		return (0);
	}
	return (str += i);
}
