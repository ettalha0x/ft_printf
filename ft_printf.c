/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:28:21 by nettalha          #+#    #+#             */
/*   Updated: 2022/11/25 11:20:48 by nettalha         ###   ########.fr       */
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

int	checkf1(va_list args, char flag)
{
	int	count;
	unsigned int 	var;

	count = 0;
	var = va_arg(args, unsigned int);
	if (flag == 'x')
	{
		if (var != 0)
		{
			count += ft_putstr("0x");
			count += ft_putnbr_hexa(var, "0123456789abcdef");
		}
		else
			count += ft_putnbr_hexa(var, "0123456789abcdef");
	}
	else if (flag == 'X')
	{
		if (var != 0)
		{
			count += ft_putstr("0X");
			count += ft_putnbr_hexa(var, "0123456789ABCDEF");
		}
		else
			count += ft_putnbr_hexa(var, "0123456789abcdef");
	}
	return (count);
}

int	checkf2(va_list args, char flag)
{
	int	count;
	long	var;

	count = 0;
	var = va_arg(args, int);
	if (flag == 'd' || flag == 'i')
	{
		if (var >= 0)
		{
			count += ft_putchar(' ');
			count += ft_putnbr(var);
		}
		else
			count += ft_putnbr(var);
	}
	return (count);
}

int	checkf3(va_list args, char flag)
{
	int	count;
	long	var;

	count = 0;
	var = va_arg(args, int);
	if (flag == 'd' || flag == 'i')
	{
		if (var >= 0)
		{
			count += ft_putchar('+');
			count += ft_putnbr(var);
		}
		else
			count += ft_putnbr(var);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (!s[i])
				break ;
			else if (s[i] == '%')
				count += ft_putchar('%');
			else if (s[i] == '#')
				count += checkf1(args, s[++i]);
			else if (s[i] == ' ')
				count += checkf2(args, s[++i]);
			else if (s[i] == '+')
				count += checkf3(args, s[++i]);
			else
				count += formats(args, s[i]);
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
