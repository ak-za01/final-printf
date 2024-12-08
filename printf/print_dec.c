/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:20:46 by anktiri           #+#    #+#             */
/*   Updated: 2024/12/07 19:03:42 by anktiri          ###   ########.fr       */
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
	if (!result)
		return (-1);
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
	if (!str)
		return (-1);
	write(1, str, ft_strlen(str));
	size = ft_strlen(str);
	free (str);
	return (size);
}
