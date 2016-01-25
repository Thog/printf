/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:44:50 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/07 12:53:52 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countdigit(int n)
{
	int		result;

	result = 0;
	while (n)
	{
		result++;
		n /= 10;
	}
	return (result);
}

char			*ft_itoa(int n)
{
	char	*result;
	int		sign;
	int		digit;

	if (!n)
		return (ft_strdup("0"));
	sign = n < 0 ? -1 : 1;
	digit = countdigit(n) + (sign == -1);
	result = ft_strnew(digit);
	if (!result)
		return (NULL);
	result += digit;
	while (n)
	{
		*--result = '0' + ((n % 10) * sign);
		n /= 10;
	}
	if (sign == -1)
		*--result = '-';
	return (result);
}
