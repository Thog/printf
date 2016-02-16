/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:58:03 by tguillem          #+#    #+#             */
/*   Updated: 2016/02/16 11:48:51 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_args(char **format, va_list *args, t_data *data)
{
	int			ret;
	t_manager	f;

	if (!(*(++*format)))
		return (0);
	if (!(ft_printf_parse_flags(format, data)) ||
			!(ft_printf_parse_width(format, args, data)) ||
			!(ft_printf_parse_accuracy(format, args, data)) ||
			!(ft_printf_parse_length(format, data)))
		return (-1);
	if (!**format)
		return (0);
	if (!(f = ft_printf_get_manager(**format)))
		f = &ft_printf_manage_null;
	ret = f(format, args, data);
	(*format)++;
	return (ret);
}

int		internal_printf(const char *format, va_list *args, int length)
{
	char	*next_arg;
	t_data	prop_data;
	int		len;

	len = 0;
	next_arg = ft_strchr(format, '%');
	if (!*format)
		return (length);
	if (!next_arg)
		return (length + write(1, format, ft_strlen(format)));
	else if (next_arg > format)
		return (internal_printf(next_arg, args, length + write(1, format,
						next_arg - format)));
	else
	{
		ft_bzero(&prop_data, sizeof(prop_data));
		if ((len = manage_args((char**)&format, args, &prop_data)) == -1)
			return (-1);
		return (internal_printf(format, args, length + len));
	}
}
