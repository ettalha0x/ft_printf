/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:47:47 by nettalha          #+#    #+#             */
/*   Updated: 2022/11/27 03:32:13 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

int		formats(va_list args, char format);
int		check_minus(va_list args, char *flag, int *i);
int		check_zero(va_list args, char *flag, int *i);
int		check_point(va_list args, char *flag, int *i);
int		check_sharp(va_list args, char flag);
int		check_space(va_list args, char flag);
int		check_pluse(va_list args, char flag);

int		ft_printf(const char *s, ...);
int		check_flags1(va_list args, char *s, int *i);
int		check_flags2(va_list args, char *s, int *i);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(long n);
int		ft_putnbr_hexa(unsigned long n, char *base);
int		ft_put_pointer(unsigned long n);
int		ft_put_unsigned(unsigned int n);
int		ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_intlen(int n, int base);


#endif
