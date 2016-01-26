#include "ft_printf.h"

ssize_t	ft_printf_manage_long(char **format, va_list *args, t_data *data)
{
	data->length = 2;
	return (ft_printf_get_manager(ft_tolower(**format))(format, args, data));
}

ssize_t				ft_printf_manage_int(char **format, va_list *args, t_data *data)
{
	intmax_t				nbr;
	char					*prefix;

	(void)format;
	if (data->got_accuracy)
		data->zero_pad = 0;
	nbr = ft_printf_get_signed_from_length(args, data);
	if (nbr < 0 || data->force_sign || data->no_sign)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			prefix = "-";
		}
		else if (data->force_sign)
			prefix = "+";
		else if (data->no_sign)
			prefix = " ";
		else
			prefix = "";
		return (ft_printf_nbrforceprefix(nbr, "0123456789", data, prefix));
	}
	else
		return (ft_printfu(nbr, data, "0123456789", NULL));
}
