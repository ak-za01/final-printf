/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:39:40 by anktiri           #+#    #+#             */
/*   Updated: 2024/12/06 06:55:20 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_conversion(char c)
{
	char	*conversions;
	int		i;

	conversions = "cspdiuxX%";
	i = 0;
	while (conversions[i])
	{
		if (conversions[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_handlers(int a, va_list args)
{
	t_handler	handlers[9];

	handlers[0] = ft_char;
	handlers[1] = ft_string;
	handlers[2] = ft_pointer;
	handlers[3] = ft_decimal;
	handlers[4] = ft_integer;
	handlers[5] = ft_unsigned;
	handlers[6] = ft_hex_lower;
	handlers[7] = ft_hex_upper;
	handlers[8] = ft_percent;
	return (handlers[a](args));
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			printed;
	int			index;

	printed = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (0);
			index = find_conversion(*format);
			if (index != -1)
				printed += ft_handlers(index, args);
		}
		else
		{
			write(1, format, 1);
			printed++;
		}
		format++;
	}
	return (va_end(args), printed);
}
