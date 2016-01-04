/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:13:14 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/04 17:21:48 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printp(void *ptr)
{
	unsigned long int value;

	value = (unsigned long int)ptr;
	return (write(1, "0x", 2) + ft_printlu(value, 16));
}
