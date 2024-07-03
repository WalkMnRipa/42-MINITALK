/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:43:59 by jcohen            #+#    #+#             */
/*   Updated: 2024/06/25 15:50:41 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_conversion_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar(c);
	return (1);
}

int	ft_conversion_string(va_list args)
{
	char	*str;
	int		nb_character;

	str = va_arg(args, char *);
	nb_character = 0;
	if (!str)
	{
		ft_putstr_printf("(null)");
		return (6);
	}
	while (str[nb_character] != '\0')
	{
		ft_putchar(str[nb_character]);
		nb_character++;
	}
	return (nb_character);
}

int	ft_conversion_decimal_integer(va_list args)
{
	long	nb;
	int		size;

	nb = va_arg(args, int);
	size = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		size++;
	}
	return (ft_putnbr_long(nb) + size);
}

int	ft_conversion_uinteger(va_list args)
{
	unsigned int	nb;

	nb = va_arg(args, unsigned int);
	return (ft_putnbr_long(nb));
}
