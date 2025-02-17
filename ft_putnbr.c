/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natlas <natlas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:07:00 by natlas            #+#    #+#             */
/*   Updated: 2025/01/24 17:16:28 by natlas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_putnbr(int d)
{
	char	*num;
	int		n;

	num = ft_itoa(d);
	if (!num)
		return (-1);
	if (ft_putstr(num) < 0)
		return (-1);
	n = ft_strlen(num);
	free(num);
	return (n);
}
