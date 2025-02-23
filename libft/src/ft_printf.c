/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:37:31 by oelleaum          #+#    #+#             */
/*   Updated: 2024/12/05 18:04:24 by oelleaum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	f_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	f_str(char *s)
{
	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	print(va_list params, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += f_char(va_arg(params, int));
	if (format == 's')
		count += f_str(va_arg(params, char *));
	if (format == 'p')
		count += f_ptr(va_arg(params, unsigned long long));
	if (format == 'd' || format == 'i')
		count += f_int(va_arg(params, int));
	if (format == 'u')
		count += f_uint(va_arg(params, unsigned int));
	if (format == 'x' || format == 'X')
		count += f_hex(va_arg(params, unsigned int), format);
	if (format == '%')
	{
		write(1, "%", 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	params;

	if (!s || (*s == '%' && *(s + 1) == '\0'))
		return (-1);
	count = 0;
	va_start(params, s);
	while (*s)
	{
		if (*s == '%')
		{
			count += print(params, *(s + 1));
			s++;
		}
		else
			count += f_char(*s);
		s++;
	}
	va_end(params);
	return (count);
}
