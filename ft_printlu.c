/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:56:50 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/04 17:10:26 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		countdigit(unsigned long int n, int base)
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

static char		*ft_ultoa_base(unsigned long int n, int base)
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
		*result += (*result >= 10 && base >= 16) ? 'a' - 10 : '0';
		n /= base;
	}
	return (result);
}

int				ft_printlu(unsigned long int nb, int base)
{
	char *tmp;
	int result;

	if (!(tmp = ft_ultoa_base(nb, base)))
		return (0);
	result = ft_prints(tmp);
	free(tmp);
	return (result);
}
