/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anktiri <anktiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:40:15 by anktiri           #+#    #+#             */
/*   Updated: 2024/12/07 18:56:24 by anktiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef int	(*t_handler)(va_list);

int		ft_printf(const char *format, ...);
int		find_conversion(char c);
int		ft_char(va_list args);
int		ft_string(va_list args);
int		ft_pointer(va_list args);
int		ft_decimal(va_list args);
int		ft_unsigned(va_list args);
int		ft_hex_lower(va_list args);
int		ft_hex_upper(va_list args);
int		ft_percent(va_list args);
size_t	ft_strlen(char *str);
int		ft_puthex(unsigned long address, int flag);
char	*ft_itoa(int n);
char	*utoa(unsigned int n);

#endif