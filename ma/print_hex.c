/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:48:17 by anktiri           #+#    #+#             */
/*   Updated: 2024/12/06 07:15:42 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long address, int flag)
{
	char	*base;
	char	tmp[20];
	int		a;

	a = 0;
	if (flag)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (address == 0)
		return (write(1, "0", 1), 1);
	while (address > 0)
	{
		tmp[a] = base[address % 16];
		address /= 16;
		a++;
	}
	tmp[a] = 0;
	while (--a >= 0)
		write(1, &tmp[a], 1);
	return (ft_strlen(tmp));
}

int	ft_hex_lower(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_puthex(nb, 0));
}

int	ft_hex_upper(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_puthex(nb, 1));
}

int	ft_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}
