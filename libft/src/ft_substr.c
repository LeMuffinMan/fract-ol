/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:15:43 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/20 16:24:51 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	i = 0;
	while (i < start && s[i] != '\0')
		i++;
	start = i;
	while (s[i] != '\0' && len > i - start)
		i++;
	len = i - start;
	res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && len > 0)
	{
		res[i] = s[start + i];
		i++;
		len--;
	}
	res[i] = 0;
	return (res);
}
