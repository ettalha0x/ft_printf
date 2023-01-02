/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:21:09 by nettalha          #+#    #+#             */
/*   Updated: 2022/12/07 22:54:44 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_minus(va_list args, char *flag, int *i)
{
	int		count;
	int		j;
	int		n;

	j = 0;
	count = 0;
	while (ft_isdigit(flag[*i]))
	{
		j = j * 10 + (flag[*i] - 48);
		(*i)++;
	}
	count += formats(args, flag[*i]);
	n = count;
	while (j-- > n)
		count += ft_putchar(' ');
	return (count);
}
