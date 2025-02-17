/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natlas <natlas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:31:29 by natlas            #+#    #+#             */
/*   Updated: 2025/01/27 15:44:36 by natlas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_handle_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'x')
		return (ft_putxl(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_putxu(va_arg(args, unsigned int)));
	if (c == 'u')
		return (ft_putu(va_arg(args, unsigned int)));
	return (-1);
}

int	ft_format_checker(char c)
{
	if (c == 'c' || c == '%' || c == 'd' || c == 'i' || c == 's' || c == 'p')
		return (1);
	else if (c == 'x' || c == 'X' || c == 'u')
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	int		tmp;

	if (!format)
		return (-1);
	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && ft_format_checker(*(format + 1)))
		{
			tmp = ft_handle_format(*(format + 1), args);
			if (tmp == -1)
				return (va_end(args), -1);
			ret += tmp;
			format++;
		}
		else if (*format == '%' && !ft_format_checker(*(format + 1)))
			return (va_end(args), -1);
		else if (++ret && (write(1, format, 1) < 0))
			return (va_end(args), -1);
		format++;
	}
	return (va_end(args), ret);
}
