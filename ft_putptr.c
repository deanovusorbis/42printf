/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natlas <natlas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:07:05 by natlas            #+#    #+#             */
/*   Updated: 2025/01/24 18:15:40 by natlas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_phexlen(unsigned long p)
{
	int		count;
	char	*hex;
	int		tmp;

	count = 0;
	hex = "0123456789abcdef";
	if (p >= 16)
	{
		tmp = ft_phexlen(p / 16);
		count += tmp;
	}
	if (write(1, &hex[p % 16], 1) < 0)
		return (-1);
	count++;
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	if (write (1, "0x", 2) < 0)
		return (-1);
	count += 2;
	count += ft_phexlen((unsigned long)ptr);
	if (count < 2)
		return (-1);
	return (count);
}
