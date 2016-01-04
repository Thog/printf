/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:03:43 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/04 17:44:26 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *s)
{
	size_t	counter;

	counter = 1;
	if (!s)
		return (0);
	while (s[counter])
		counter++;
	if (!s[0])
		return (0);
	return (counter);
}

int			ft_printc(int cp)
{
	int		result;

	result = 0;
	if (cp < 128)
		result = ft_putchar(cp);
	else if (cp < 2048)
		result += ft_putchar(192 | (cp >> 6)) + ft_putchar(128 | (cp & 63));
	else if (cp < 65536)
	{
		result += ft_putchar(224 | (cp >> 12));
		result += ft_putchar(128 | ((cp >> 6) & 63));
		result += ft_putchar(128 | (cp & 63));
	}
	else if (cp < 1114112)
	{
		result += ft_putchar(240 | (cp >> 18));
		result += ft_putchar(128 | ((cp >> 12) & 63));
		result += ft_putchar(128 | ((cp >> 6) & 63));
		result += ft_putchar(128 | (cp & 63));
	}
	return (result);
}

int			ft_prints(char *str)
{
	int		size;

	size = ft_strlen(str);
	if (size)
		return (write(1, str, size));
	return (0);
}

int			compute_arg(char target, va_list args)
{
	if (target == 's' || target == 'S')
		return (ft_prints(va_arg(args, char*)));
	else if (target == 'c' || target == 'C')
		return (ft_printc(va_arg(args, int)));
	else if (target == 'd' || target == 'D')
		return (ft_printi(va_arg(args, int), 10));
	else if (target == 'u' || target == 'U')
		return (ft_printu(va_arg(args, unsigned int), 10));
	else if (target == 'x' || target == 'X')
		return (ft_printu(va_arg(args, unsigned int), 16));
	else if (target == 'p')
		return (ft_printp(va_arg(args, void*)));
	return (write(1, &target, 1));
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		args;
	int			i;
	int			result;

	i = 0;
	result = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			result += compute_arg(format[i + 1], args);
			i++;
		}
		else
			result += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (result);
}
