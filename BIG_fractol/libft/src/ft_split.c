/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:28:17 by oelleaum          #+#    #+#             */
/*   Updated: 2024/11/20 16:23:24 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strs(const char *s, char c)
{
	int	strs;
	int	i;

	i = 0;
	strs = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			strs++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (strs);
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
}

static char	*ft_strdup_custom(char *s, int start, char c)
{
	int		i;
	int		len;
	char	*dup;

	i = start;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (len--)
		dup[i++] = s[start++];
	dup[i] = '\0';
	return (dup);
}

static char	**fill_splited(char **splited, const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i])
		{
			splited[j] = ft_strdup_custom((char *)s, i, c);
			if (splited[j] == NULL)
			{
				ft_free(splited);
				return (NULL);
			}
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	splited[j] = NULL;
	return (splited);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;

	if (!s)
		return (NULL);
	splited = malloc(sizeof(char *) * ((count_strs(s, c)) + 1));
	if (!splited)
		return (NULL);
	return (fill_splited(splited, s, c));
}
