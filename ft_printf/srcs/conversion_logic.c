/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:55:04 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/29 15:03:20 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_make_conversion(char type, va_list args)
{
	if (type == 'c')
		return (ft_conversion_char(args));
	if (type == 's')
		return (ft_conversion_string(args));
	if (type == 'p')
		return (ft_conversion_pointer(args));
	if (type == 'd' || type == 'i')
		return (ft_conversion_decimal_integer(args));
	if (type == 'u')
		return (ft_conversion_uinteger(args));
	if (type == 'x')
		return (ft_conversion_hexa(args, false));
	if (type == 'X')
		return (ft_conversion_hexa(args, true));
	if (type == '%')
		return (ft_conversion_percentage());
	return (0);
}
