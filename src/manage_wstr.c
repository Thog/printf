
#include "ft_printf.h"

void	ft_putnwstr(const wchar_t *str, size_t len)
{
	size_t	i;

	i = 0;
	while (*str && i < len)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		if (i <= len)
			ft_putwchar(*str++);
	}
}

static size_t	calc_wstrlen(wchar_t *str, int precision, size_t i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (calc_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (calc_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (calc_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (calc_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

ssize_t			ft_printf_manage_wstr(char **format, va_list *args, t_data *data)
{
	wchar_t	*str;
	size_t	strlen;

	(void)format;
	(void)data;
	str = va_arg(*args, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	strlen = data->got_accuracy ? calc_wstrlen(str, data->accuracy, 0) :
			ft_wstrlen(str);
	if (data->got_width && !data->right_pad)
		ft_printf_width_pad(strlen, data->width, data->zero_pad ? '0' : ' ');
	ft_putnwstr(str, strlen);
	if (data->got_width && data->right_pad)
		ft_printf_width_pad(strlen, data->width, ' ');
	return (data->got_width ? (size_t)(ft_max(strlen, data->width)) : strlen);
}