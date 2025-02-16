/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:08:08 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/15 14:58:03 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_protected(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strlengnl(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return ((size_t)i);
}

char	*ft_strjoin_protected(char *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		j;

	i = 0;
	joined = malloc(sizeof(char) * (ft_strlengnl(s1) + ft_strlengnl(s2) + 1));
	if (joined == NULL)
	{
		free((char *)s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	free(s1);
	return (joined);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*des;
	unsigned char	*sr;

	des = dest;
	sr = (unsigned char *)src;
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

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}
