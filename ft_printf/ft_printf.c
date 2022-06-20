/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:37:38 by wboutzou          #+#    #+#             */
/*   Updated: 2021/12/02 21:55:32 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, s);
	while (*s)
	{	
		if (*s == '%')
		{
			s++;
			count += ft_check((char)*s, args);
		}
		else
		{
			ft_putchar(*s);
			count++;
		}
		s++;
	}
	va_end(args);
	return (count);
}
