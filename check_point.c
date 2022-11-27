/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:21:51 by nettalha          #+#    #+#             */
/*   Updated: 2022/11/27 03:54:19 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_point(va_list args, char *flag, int *i)
{
	int count;
	int j;
	int var;

	j = 0;
	count = 0;
	var = va_arg(args, int);
	while (ft_isdigit(flag[*i]))
	{
		j = j * 10 + (flag[*i] - 48);
		(*i)++;
	}

	if (flag[*i] != 'X' && flag[*i] != 'x')
	{
		while (j-- > ft_intlen(var, 10))
			count += ft_putchar('0');
		if (flag[*i] == 'd' || flag[*i] == 'i')
			count += ft_putnbr(var);
		else if (flag[*i] == 'u')
			count += ft_put_unsigned(var);
	}
	else if (flag[*i] == 'X' || flag[*i] == 'x')
	{
		while (j-- > ft_intlen(var, 16))
			count += ft_putchar('0');
		if (flag[*i] == 'x')
			count += ft_putnbr_hexa(var, "0123456789abcdef");
		else if (flag[*i] == 'X')
			count += ft_putnbr_hexa(var, "0123456789ABCDEF");
	}
	return (count);
}
