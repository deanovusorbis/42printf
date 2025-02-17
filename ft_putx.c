/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natlas <natlas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:29:47 by natlas            #+#    #+#             */
/*   Updated: 2025/01/24 15:40:23 by natlas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	ft_hex_len(unsigned int x)
{
	int	len;

	len = 0;
	if (x == 0)
		return (1);
	while (x > 0)
	{
		len++;
		x /= 16;
	}
	return (len);
}

int	ft_putxl(unsigned int x)
{
	char	*hex;
	char	*str;
	int		len;

	hex = "0123456789abcdef";
	len = ft_hex_len(x);
	str = malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	if (x == 0)
		str[0] = '0';
	while (x > 0)
	{
		str[--len] = hex[x % 16];
		x /= 16;
	}
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	ft_putxu(unsigned int x)
{
	char	*hex;
	char	*str;
	int		len;

	hex = "0123456789ABCDEF";
	len = ft_hex_len(x);
	str = malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	if (x == 0)
		str[0] = '0';
	while (x > 0)
	{
		str[--len] = hex[x % 16];
		x /= 16;
	}
	if (ft_putstr(str) < 0)
		return (-1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
