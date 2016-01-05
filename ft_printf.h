/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:56:21 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/04 17:43:41 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

char	*ft_strdup(const char *s);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
int		ft_putchar(int c);
int		ft_printi(int nb, int base);
int		ft_printu(unsigned int nb, int base);
int		ft_printp(void *ptr);
int		ft_printlu(unsigned long int nb, int base);
int		ft_printc(int c);
int		ft_prints(char *str);
int		ft_printf(const char *restrict format, ...);
#endif
