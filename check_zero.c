/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:21:33 by nettalha          #+#    #+#             */
/*   Updated: 2022/11/28 21:49:47 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_leen(unsigned long n, int base)
{
	int	i;
	unsigned long	m;

	m = n;
	i = 0;
	while (m != 0)
	{
		m = m / base;
		i++;
	}
	return (i);
}

int check_zero(va_list args, char *flag, int *i)
{
	int count;
	int j;
	long var;
	int k;

	j = 0;
	count = 0;
	k = 0;
	while (ft_isdigit(flag[*i]))
	{
		j = j * 10 + (flag[*i] - 48);
		(*i)++;
	}
	var = va_arg(args, int);
	if (flag[*i] == 'd' || flag[*i] == 'i')
	{
		if (var < 0)
		{
			k = 1;
			count += ft_putchar('-');
			var = var * -1;
		}
		k += ft_intlen(var, 10);
		while (j-- > k)
			count += ft_putchar('0');
	}
	else if (flag[*i] == 'u')
	{
		if (var == 0)
			return (ft_putchar('0'));
		while (j-- > ft_leen((unsigned long)var, 10))
			count += ft_putchar('0');
	}

	if (flag[*i] == 'd' || flag[*i] == 'i')
		count += ft_putnbr(var);
	else if (flag[*i] == 'u')
		count += ft_put_unsigned((unsigned int)var);
	else if (flag[*i] == 'x')
		count += ft_putnbr_hexa(var, "0123456789abcdef");
	else if (flag[*i] == 'X')
		count += ft_putnbr_hexa(var, "0123456789ABCDEF");
	return (count);
}
