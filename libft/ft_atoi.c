/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:04:04 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/22 12:14:51 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
void	test_ft_atoi(void)
{
	// Tests de base
	assert(ft_atoi("0") == 0);
	assert(ft_atoi("123") == 123);
	assert(ft_atoi("-123") == -123);
	assert(ft_atoi("+123") == 123);
	// Tests avec espaces et caractères de contrôle
	assert(ft_atoi("   42") == 42);
	assert(ft_atoi("\t\n\v\f\r 42") == 42);
	assert(ft_atoi("   -42") == -42);
	assert(ft_atoi("\t\n\v\f\r -42") == -42);
	// Tests avec caractères non numériques après le nombre
	assert(ft_atoi("123abc") == 123);
	assert(ft_atoi("-123abc") == -123);
	// Tests avec grands nombres
	assert(ft_atoi("2147483647") == 2147483647);   // INT_MAX
	assert(ft_atoi("-2147483648") == -2147483648); // INT_MIN
	// Test limite
	assert(ft_atoi("") == 0);
	printf("Tous les tests sont passés avec succès.\n");
}

int	main(void)
{
	test_ft_atoi();
	return (0);
}
*/