/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sharp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:00:38 by nettalha          #+#    #+#             */
/*   Updated: 2022/11/25 20:01:26 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_sharp(va_list args, char flag)
{
	int				count;
	unsigned int	var;
	char			*base;

	count = 0;
	var = va_arg(args, unsigned int);
	if (flag == 'x')
	{
		base = "0123456789abcdef";
		if (var != 0)
			count += ft_putstr("0x") + ft_putnbr_hexa(var, base);
		else
			count += ft_putnbr_hexa(var, base);
	}
	else if (flag == 'X')
	{
		base = "0123456789ABCDEF";
		if (var != 0)
			count += ft_putstr("0X") + ft_putnbr_hexa(var, base);
		else
			count += ft_putnbr_hexa(var, base);
	}
	return (count);
}
