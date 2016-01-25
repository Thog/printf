/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:39:16 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/23 17:44:35 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	counter;

	counter = 0;
	while (s[counter])
	{
		ft_putchar_fd(s[counter], fd);
		counter++;
	}
}
