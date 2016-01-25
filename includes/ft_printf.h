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

int		ft_printchar(int c);
int		ft_printi(int nb, int base);
int		ft_printu(unsigned int nb, int base, char c);
int		ft_printp(void *ptr);
int		ft_printlu(unsigned long int nb, int base);
int		ft_printc(int c);
int		ft_prints(char *str);
int		ft_iscntrl(int c);
int		ft_printf(const char *format, ...);
#endif
