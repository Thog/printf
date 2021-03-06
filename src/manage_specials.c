/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_specials.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:22:36 by tguillem          #+#    #+#             */
/*   Updated: 2016/02/16 14:43:53 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_printf_manage_ptr(char **format, va_list *args, t_data *data)
{
	(void)format;
	data->length = 4;
	if (data->got_accuracy)
		data->zero_pad = 0;
	return (ft_printf_nbrforceprefix(
				ft_printf_get_unsigned_from_length(args, data),
				"0123456789abcdef", data, "0x"));
}

ssize_t	ft_printf_manage_percent(char **format, va_list *args, t_data *data)
{
	(void)format;
	(void)args;
	if (data->got_width && !data->right_pad)
		ft_printf_width_pad(1, data->width, data->zero_pad ? '0' : ' ');
	ft_putchar('%');
	if (data->got_width && data->right_pad)
		ft_printf_width_pad(1, data->width, ' ');
	return (data->got_width ? ft_max(data->width, 1) : 1);
}

ssize_t	ft_printf_manage_null(char **format, va_list *args, t_data *data)
{
	(void)args;
	if (data->got_width && !data->right_pad)
		ft_printf_width_pad(1, data->width, data->zero_pad ? '0' : ' ');
	ft_putchar(**format);
	if (data->got_width && data->right_pad)
		ft_printf_width_pad(1, data->width, ' ');
	return (data->got_width ? ft_max(data->width, 1) : 1);
}
