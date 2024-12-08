/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:25:14 by anktiri           #+#    #+#             */
/*   Updated: 2024/12/06 07:36:32 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_ft_ln(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	handle_sign(unsigned int *result, char *str)
{
	if (*result < 0)
	{
		str[0] = '-';
		*result *= -1;
	}
	else if (*result == 0)
	{
		str[0] = '0';
	}
}

void	convert_to_str(char *str, unsigned int result, int len)
{
	while (result)
	{
		str[len--] = (result % 10) + '0';
		result /= 10;
	}
}

char	*utoa(unsigned int nb)
{
	char			*str;
	int				len;

	len = _ft_ln(nb);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	handle_sign(&nb, str);
	convert_to_str(str, nb, len - 1);
	return (str);
}
