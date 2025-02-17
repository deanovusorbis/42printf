/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natlas <natlas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:54:41 by natlas            #+#    #+#             */
/*   Updated: 2024/12/14 15:33:29 by natlas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*c;

	i = 0;
	c = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

static size_t	ft_numlen(int num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		len = 1;
	if (num < 0)
	{
		len++;
	}
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static int	ft_dvalueset(int len, int num)
{
	int	dvalue;

	dvalue = 1;
	while (len-- > 1)
		dvalue *= 10;
	if (num < 0)
		dvalue *= -1;
	return (dvalue);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;
	int		i;
	int		digit;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_numlen(n);
	nbr = malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	i = 0;
	if (n < 0)
		--len;
	if (n < 0)
		nbr[i++] = '-';
	while (len > 0)
	{
		digit = n / ft_dvalueset(len, n);
		nbr[i++] = digit + '0';
		n -= digit * ft_dvalueset(len, n);
		len--;
	}
	nbr[i] = '\0';
	return (nbr);
}
