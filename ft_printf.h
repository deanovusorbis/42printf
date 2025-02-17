/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natlas <natlas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:16:08 by natlas            #+#    #+#             */
/*   Updated: 2024/12/14 16:04:52 by natlas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>

char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putnbr(int d);
int		ft_putptr(void *ptr);
int		ft_putstr(char *s);
int		ft_putu(unsigned int u);
int		ft_putxl(unsigned int x);
int		ft_putxu(unsigned int x);
int		ft_printf(const char *format, ...);

#endif
