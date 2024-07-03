/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:22:24 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/23 12:33:41 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calculate_length(int n)
{
	size_t	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	size_t			len_n;
	unsigned int	num;
	char			*itoa;

	len_n = calculate_length(n);
	itoa = (char *)malloc(len_n + 1);
	if (!itoa)
		return (NULL);
	if (n < 0)
	{
		itoa[0] = '-';
		num = (unsigned int)(-n);
	}
	else
		num = (unsigned int)n;
	itoa[len_n] = '\0';
	if (num == 0)
		itoa[--len_n] = '0';
	while (num > 0)
	{
		itoa[--len_n] = (num % 10) + '0';
		num /= 10;
	}
	return (itoa);
}
