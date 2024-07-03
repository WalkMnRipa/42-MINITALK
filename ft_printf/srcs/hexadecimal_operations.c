/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:54:21 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/29 15:03:18 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_hexa(unsigned long long n, bool capital)
{
	int		size;
	char	*hexa_digits;

	size = 0;
	if (capital)
		hexa_digits = "0123456789ABCDEF";
	else
		hexa_digits = "0123456789abcdef";
	if (n >= 16)
		size += ft_putnbr_hexa(n / 16, capital);
	ft_putchar(hexa_digits[n % 16]);
	size++;
	return (size);
}

int	ft_putnbrhexa_ptr(uintptr_t n)
{
	int		size;
	char	*hexa_digits;

	size = 0;
	hexa_digits = "0123456789abcdef";
	if (n >= 16)
		size += ft_putnbrhexa_ptr(n / 16);
	ft_putchar(hexa_digits[n % 16]);
	size++;
	return (size);
}
