#include "ft_printf.h"

static void		init_managers(t_manager *manager)
{
	//manager['%'] = &ft_printf_manage_percent;
	manager['s'] = &ft_printf_manage_str;
	manager['S'] = &ft_printf_manage_wstr;
	manager['d'] = &ft_printf_manage_int;
	manager['D'] = &ft_printf_manage_long;
	manager['i'] = &ft_printf_manage_int;
	//manager['o'] = &ft_printf_manage_octal;
	manager['O'] = &ft_printf_manage_long;
	manager['u'] = &ft_printf_manage_long;
	manager['U'] = &ft_printf_manage_long;
	//manager['x'] = &ft_printf_manage_hexa;
	//manager['X'] = &ft_printf_manage_hexa;
	//manager['p'] = &ft_printf_manage_ptr;
	manager['c'] = &ft_printf_manage_char;
	manager['C'] = &ft_printf_manage_wchar;
}


t_manager		ft_printf_get_manager(char c)
{
	static t_manager	*managers = NULL;

	if (!managers)
	{
		managers = ft_memalloc(sizeof(*managers) * 256);
		if (managers != NULL)
			init_managers(managers);
	}
	return (managers[(int)c]);
}