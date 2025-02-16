/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:46:59 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/20 16:24:45 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char *set)
{
	int	i;
	int	inset;

	i = 0;
	inset = 0;
	while (set[i] && inset == 0)
	{
		if (c == set[i])
			inset = 1;
		i++;
	}
	return (inset);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed;
	int		start;
	int		stop;
	int		i;

	start = -1;
	stop = -1;
	i = 0;
	while (s1[i] && start < 0)
	{
		if (is_in_set(s1[i], (char *)set) == 0)
			start = i;
		i++;
	}
	i = ft_strlen((char *)s1) + 1;
	while (--i > 0 && stop < 0)
	{
		if ((is_in_set(s1[i], (char *)set) == 1 || s1[i] == '\0')
			&& is_in_set(s1[i - 1], (char *)set) == 0)
			stop = i;
	}
	trimed = ft_substr(s1, start, stop - start);
	return (trimed);
}
