/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nettalha <nettalha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:28:21 by nettalha          #+#    #+#             */
/*   Updated: 2022/11/27 01:43:54 by nettalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	check_flags1(va_list args, char *s, int *i)
{
	int	count;

	count = 0;
	if (s[*i] == '-')
	{
		(*i)++;
		while (s[*i] == '-')
			(*i)++;
		count += check_minus(args, s, i);
	}
	else if (s[*i] == '0')
	{
		(*i)++;
		while (s[*i] == '0')
			(*i)++;
		count += check_zero(args, s, i);
	}
	else if (s[*i] == '.')
	{
		(*i)++;
		while (s[*i] == '.')
			(*i)++;
		count += check_point(args, s, i);
	}
	return (count);
}

int	check_flags2(va_list args, char *s, int *i)
{
	int	count;

	count = 0;
	if (s[*i] == '#')
	{
		(*i)++;
		while (s[*i] == '#')
			(*i)++;
		count += check_sharp(args, s[*i]);
	}
	else if (s[*i] == ' ')
	{
		(*i)++;
		while (s[*i] == ' ')
			(*i)++;
		count += check_space(args, s[*i]);
	}
	else if (s[*i] == '+')
	{
		(*i)++;
		while (s[*i] == '+')
			(*i)++;
		count += check_pluse(args, s[*i]);
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
			if (s[i] == '%')
				count += ft_putchar('%');
			else if (s[i] == '-' || s[i] == '0' || s[i] == '.')
				count += check_flags1(args, (char *)s, &i);
			else if (s[i] == '#' || s[i] == ' ' || s[i] == '+')
				count += check_flags2(args, (char *)s, &i);
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
