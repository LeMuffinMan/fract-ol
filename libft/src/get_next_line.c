/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:23:18 by oelleaum          #+#    #+#             */
/*   Updated: 2025/02/15 14:57:56 by oelleaum         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cleaner(char *buf, char *line, ssize_t nb)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	line[i + 1] = '\0';
	ft_memmove(buf, ft_strchr_protected(buf, '\n') + 1, nb);
}

static char	*reader(int fd, char *buf, char *line)
{
	ssize_t	nb;

	while (ft_strchr_protected(buf, '\n') == NULL)
	{
		nb = read(fd, buf, BUFFER_SIZE);
		if (nb < 0 || (nb == 0 && !(*line)))
		{
			free(line);
			buf[0] = '\0';
			return (NULL);
		}
		if (nb == 0 && *line)
		{
			buf[0] = '\0';
			return (line);
		}
		buf[nb] = '\0';
		line = ft_strjoin_protected(line, buf);
		if (line == NULL)
		{
			ft_bzero(buf, BUFFER_SIZE + 1);
			return (NULL);
		}
	}
	return (cleaner(buf, line, nb), line);
}

static char	*nl_seeker(int fd, char *buf, char *line)
{
	int	i;

	if (ft_strchr_protected(buf, '\n'))
	{
		i = 0;
		while (line[i] != '\n' && line[i])
			i++;
		line[i + 1] = '\0';
		ft_memmove(buf, ft_strchr_protected(buf, '\n') + 1, BUFFER_SIZE);
		return (line);
	}
	line = reader(fd, buf, line);
	if (line == NULL)
		return (NULL);
	return (line);
}

static char	*ft_strdupgnl(const char *s)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlengnl(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * (1));
	if (line == NULL)
		return (NULL);
	*line = '\0';
	line = ft_strjoin_protected(line, buf);
	if (line == NULL)
		return (NULL);
	line = nl_seeker(fd, buf, line);
	if (line == NULL)
		return (NULL);
	l = ft_strdupgnl(line);
	free(line);
	return (l);
}
