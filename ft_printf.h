/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:47:47 by nettalha          #+#    #+#             */
/*   Updated: 2022/11/25 20:07:48 by nettalha         ###   ########.fr       */
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
int		check_sharp(va_list args, char flag);
int		check_space(va_list args, char flag);
int		check_pluse(va_list args, char flag);
int		ft_printf(const char *s, ...);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(long n);
int		ft_putnbr_hexa(unsigned long n, char *base);
int		ft_put_pointer(unsigned long n);
int		ft_put_unsigned(unsigned int n);
size_t	ft_strlen(const char *s);

#endif
