/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:56:50 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/04 17:41:15 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		countdigit(unsigned int n, int base)
{
	int		result;

	result = 0;
	while (n)
	{
		result++;
		n /= base;
	}
	return (result);
}

static char		*ft_utoa_base(unsigned int n, int base, char c)
{
	char	*result;
	int		digit;

	if (!n)
		return (ft_strdup("0"));
	digit = countdigit(n, base);
	result = ft_strnew(digit);
	if (!result)
		return (NULL);
	result += digit;
	while (n)
	{
		*--result = ((n % base));
		*result += (*result >= 10 && base >= 16) ? c - 10 : '0';
		n /= base;
	}
	return (result);
}

int				ft_printu(unsigned int nb, int base, char c)
{
	char	*tmp;
	int		result;

	if (!(tmp = ft_utoa_base(nb, base, c)))
		return (0);
	result = ft_prints(tmp);
	free(tmp);
	return (result);
}
