/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fomats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:57:04 by nettalha          #+#    #+#             */
/*   Updated: 2022/11/25 19:58:04 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formats(va_list args, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_put_pointer(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_put_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		count += ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (count);
}
