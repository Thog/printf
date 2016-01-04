/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:56:50 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/04 16:17:56 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		countdigit(int n, int base)
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

static char		*ft_itoa_base(int n, int base)
{
	char	*result;
	int		sign;
	int		digit;

	if (!n)
		return (ft_strdup("0"));
	sign = n < 0 ? -1 : 1;
	digit = countdigit(n, base) + (sign == -1);
	result = ft_strnew(digit);
	if (!result)
		return (NULL);
	result += digit;
	while (n)
	{
		*--result = ((n % base) * sign);
		*result += (*result >= 10 && base >= 16) ? 'a' - 10 : '0';
		n /= base;
	}
	if (sign == -1)
		*--result = '-';
	return (result);
}

int				ft_printi(int nb, int base)
{
	char *tmp;
	int result;

	if (!(tmp = ft_itoa_base(nb, base)))
		return (0);
	result = ft_prints(tmp);
	free(tmp);
	return (result);
}
