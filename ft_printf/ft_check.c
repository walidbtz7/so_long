/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 05:40:24 by wboutzou          #+#    #+#             */
/*   Updated: 2021/12/02 21:53:37 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list args)
{	
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (c == 'X')
		count += fthexa(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	if (c == 'x')
		count += fthexa(va_arg(args, unsigned int), "0123456789abcdef", 16);
	if (c == 'u')
		count += fthexa(va_arg(args, unsigned int), "0123456789", 10);
	if (c == 'p')
	{
		ft_putstr("0x");
		count += 2;
		count += ft_phexa(va_arg(args, unsigned long long));
	}
	if (c == '%')
		count += ft_putchar('%');
	return (count);
}
