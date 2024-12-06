/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:56:53 by anktiri           #+#    #+#             */
/*   Updated: 2024/12/06 07:25:51 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	a;

	a = 0;
	if (!str)
		return (a);
	while (str[a])
		a++;
	return (a);
}

int	ft_char(va_list args)
{
	char	a;

	a = va_arg(args, int);
	write(1, &a, 1);
	return (1);
}

int	ft_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_pointer(va_list args)
{
	unsigned long	address;

	address = va_arg(args, unsigned long);
	write(1, "0x", 2);
	return (2 + ft_puthex(address, 0));
}
