/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:25:14 by anktiri           #+#    #+#             */
/*   Updated: 2024/12/06 06:50:53 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ln(int n)
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

void	ft_handle_sign(long *result, char *str)
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

void	ft_convert_to_str(char *str, long result, int len)
{
	while (result)
	{
		str[len--] = (result % 10) + '0';
		result /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	result;
	int		len;

	result = n;
	len = ft_ln(result);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_handle_sign(&result, str);
	ft_convert_to_str(str, result, len - 1);
	return (str);
}
