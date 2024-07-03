/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_conversions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:42:37 by jcohen            #+#    #+#             */
/*   Updated: 2024/06/25 15:46:52 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_conversion_pointer(va_list args)
{
	void		*ptr;
	int			size;
	uintptr_t	ad;

	ptr = va_arg(args, void *);
	size = 0;
	if (!ptr)
	{
		ft_putstr_printf("(nil)");
		size = 5;
	}
	else
	{
		ad = (uintptr_t)ptr;
		ft_putstr_printf("0x");
		size = 2 + ft_putnbrhexa_ptr(ad);
	}
	return (size);
}

int	ft_conversion_hexa(va_list args, bool choice)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_putnbr_hexa(n, choice));
}

int	ft_conversion_percentage(void)
{
	ft_putchar('%');
	return (1);
}
