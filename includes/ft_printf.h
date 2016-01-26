/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:56:21 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/07 13:18:35 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <inttypes.h>

typedef struct	s_data
{
	int				prefix;
	int				zero_pad;
	int				right_pad;
	int				force_sign;
	int				no_sign;
	int				got_width;
	int				got_accuracy;
	unsigned int	width;
	unsigned int	accuracy;
	unsigned int	length;
}				t_data;

typedef ssize_t		(*t_manager)(char**, va_list*, t_data*);
t_manager			ft_printf_get_manager(char c);
intmax_t			ft_printf_get_signed_from_length(va_list *args, t_data *data);
ssize_t				ft_printfu(uintmax_t nbr, t_data *data, char *base, char *prefix);
char				*ft_printf_parse_flags(char **format, t_data *data);
char				*ft_printf_parse_width(char **format, va_list *list, t_data *data);
char				*ft_printf_parse_accuracy(char **format, va_list *list, t_data *data);
char				*ft_printf_parse_length(char **format, t_data *data);
ssize_t				ft_printf_manage_wchar(char **format, va_list *args, t_data *data);
ssize_t				ft_printf_manage_char(char **format, va_list *args, t_data *data);
ssize_t				ft_printf_manage_str(char **format, va_list *args, t_data *data);
ssize_t				ft_printf_manage_wstr(char **format, va_list *args, t_data *data);
ssize_t				ft_printf_manage_long(char **format, va_list *args, t_data *data);
ssize_t				ft_printf_manage_int(char **format, va_list *args, t_data *data);
ssize_t				ft_printf_nbrforceprefix(uintmax_t nbr, char *base, t_data *data, char *prefix);
unsigned int		ft_printf_maxstrlen(uintmax_t nbr, char *base, char *p, t_data *data);
unsigned int		ft_printf_nbrlen(uintmax_t nbr, char *base);
int					internal_printf(const char *format, va_list *args, int length);
void				ft_printf_width_pad(int nbrstrlen, int width, char padwith);
int					ft_printf(const char *format, ...);
#endif
