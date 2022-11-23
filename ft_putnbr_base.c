/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:56:29 by nettalha          #+#    #+#             */
/*   Updated: 2022/10/27 22:35:50 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 0 && n < 16)
		count += ft_putchar(base[n]);
	else if (n >= 16)
	{
		count += ft_putnbr_base(n / 16, base);
		count += ft_putnbr_base(n % 16, base);
	}
	return (count);
}
