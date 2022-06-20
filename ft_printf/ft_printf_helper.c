/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wboutzou <wboutzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:37:49 by wboutzou          #+#    #+#             */
/*   Updated: 2021/12/02 21:53:20 by wboutzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fthexa(unsigned int a, char *base, int b)
{
	int	count;

	count = 0;
	if (a < (unsigned int)b)
	{
		count += ft_putchar(base[a]);
	}
	else
	{
		count += fthexa(a / b, base, b);
		count += ft_putchar(base[a % b]);
	}
	return (count);
}

int	ft_phexa(unsigned long long a)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (a < 16)
	{
		count += ft_putchar(base[a]);
	}
	else
	{
		count += ft_phexa(a / 16);
		count += ft_putchar(base[a % 16]);
	}
	return (count);
}

int	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int a)
{
	int		i;
	long	nb;

	i = 0;
	nb = (long)a;
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
	{
		i += ft_putchar(nb + '0');
	}
	return (i);
}
