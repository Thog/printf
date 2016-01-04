/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:56:50 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/04 15:19:11 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printi(int nb, int base)
{
	int	result;
	int	temp;
	int	size;

	result = 0;
	if (nb == -2147483648)
		return (ft_prints("-2147483648"));
	size = 1;
	if (nb < 0)
	{
		result += ft_putchar('-');
		nb = -nb;
	}
	temp = nb;
	while ((temp /= base) > 0)
		size *= base;
	temp = nb;
	while (size)
	{
		result += ft_putchar((char)((temp / size)) + 48);
		temp %= size;
		size /= base;
	}
	return (result);
}
