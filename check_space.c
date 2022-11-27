/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:02:15 by nettalha          #+#    #+#             */
/*   Updated: 2022/11/27 01:11:03 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_space(va_list args, char flag)
{
	int		count;
	long	var;

	count = 0;
	var = va_arg(args, int);
	if (flag == 'd' || flag == 'i')
	{
		if (var >= 0)
			count += ft_putchar(' ');
		count += ft_putnbr(var);
	}
	return (count);
}
