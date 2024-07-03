/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:54:55 by jcohen            #+#    #+#             */
/*   Updated: 2024/06/25 15:50:22 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr_printf(const char *str);
int		ft_strlen_printf(const char *str);
int		ft_putnbr_long(long n);
int		ft_putnbr_hexa(unsigned long long n, bool capital);
int		ft_putnbrhexa_ptr(uintptr_t n);

int		ft_conversion_char(va_list args);
int		ft_conversion_string(va_list args);
int		ft_conversion_pointer(va_list args);
int		ft_conversion_decimal_integer(va_list args);
int		ft_conversion_uinteger(va_list args);
int		ft_conversion_hexa(va_list args, bool choice);
int		ft_conversion_percentage(void);

int		ft_make_conversion(char type, va_list args);

int		ft_printf(const char *format, ...);

#endif