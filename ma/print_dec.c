/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:20:46 by anktiri           #+#    #+#             */
/*   Updated: 2024/12/06 07:31:31 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimal(va_list args)
{
	char	*result;
	int		size;
	int		nbr;

	nbr = va_arg(args, int);
	result = ft_itoa(nbr);
	write(1, result, ft_strlen(result));
	size = ft_strlen(result);
	free (result);
	return (size);
}

int	ft_integer(va_list args)
{
	char	*result;
	int		size;
	int		nbr;

	nbr = va_arg(args, int);
	result = ft_itoa(nbr);
	write(1, result, ft_strlen(result));
	size = ft_strlen(result);
	free (result);
	return (size);
}

int	ft_unsigned(va_list args)
{
	unsigned int	nb;
	int				size;
	char			*str;

	nb = va_arg(args, unsigned int);
	str = utoa(nb);
	write(1, str, ft_strlen(str));
	size = ft_strlen(str);
	free (str);
	return (size);
}
