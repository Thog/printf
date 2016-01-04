/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:51:10 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/04 15:51:50 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*result;

	result = (char *)malloc(size + 1);
	if (result == NULL)
	{
		return (result);
	}
	ft_bzero(result, size + 1);
	return (result);
}
