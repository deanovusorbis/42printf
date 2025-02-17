/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natlas <natlas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:10:07 by natlas            #+#    #+#             */
/*   Updated: 2025/01/24 15:40:09 by natlas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

static int	ft_unsigned_len(unsigned int u)
{
	int	len;

	len = 0;
	if (u == 0)
		return (1);
	while (u > 0)
	{
		len++;
		u /= 10;
	}
	return (len);
}

int	ft_putu(unsigned int u)
{
	char	*str;
	int		len;

	len = ft_unsigned_len(u);
	str = malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	if (u == 0)
		str[0] = '0';
	while (u > 0)
	{
		str[--len] = (u % 10) + '0';
		u /= 10;
	}
	if (ft_putstr(str) < 0)
		return (-1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
