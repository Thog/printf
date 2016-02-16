/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 07:47:34 by tguillem          #+#    #+#             */
/*   Updated: 2016/02/16 10:51:29 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_digit(int value, int base)
{
	int n;

	n = 0;
	while (value)
	{
		n++;
		value /= base;
	}
	return (n);
}

char			*ft_itoa_base(int value, int base)
{
	char		*result;
	int			size;
	int			sign;

	if (!value)
		return (ft_strdup("0"));
	sign = value > 0 ? 1 : -1;
	size = count_digit(value, base) + (sign == -1 && base == 10);
	if (!(result = ft_strnew(sizeof(char) * (size))))
		return (NULL);
	while (value)
	{
		*--result = BASE_16[(value % base) * sign];
		value /= base;
	}
	if (sign == -1 && base == 10)
		*--result = '-';
	return (result);
}
