/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 01:41:42 by nettalha          #+#    #+#             */
/*   Updated: 2022/11/27 03:33:39 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(int n, int base)
{
	int	i;
	int	m;

	m = n;
	i = 0;
	while (m != 0)
	{
		m = m / base;
		i++;
	}
	if (n > 0)
		return (i);
	else if (n == 0)
		return (1);
	else
		return (i + 1);
}
