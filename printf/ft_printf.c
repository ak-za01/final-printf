/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:39:40 by anktiri           #+#    #+#             */
/*   Updated: 2024/12/11 04:43:22 by anktiri          ###   ########.fr       */
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
	handlers[4] = ft_decimal;
	handlers[5] = ft_unsigned;
	handlers[6] = ft_hex_lower;
	handlers[7] = ft_hex_upper;
	handlers[8] = ft_percent;
	return (handlers[a](args));
}

int	handle_error(const char **format, va_list args)
{
	int	printed;
	int	index;

	printed = 0;
	*format += 1;
	if (*format == '\0')
		return (0);
	if (find_conversion(**format) != -1)
	{
		index = ft_handlers(find_conversion(**format), args);
		if (index == -1)
			return (-1);
		printed += index;
	}
	else
	{
		write(1, *format, 1);
		printed++;
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			printed;
	int			a;

	printed = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			a = handle_error(&format, args);
			if (a == -1)
				return (-1);
			if (*format == '\0')
				return (printed);
			printed += a;
		}
		else
			printed += write(1, format, 1);
		format++;
	}
	return (va_end(args), printed);
}
