/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:28:04 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/22 13:07:30 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str_join;

	if (!s1 || !s2)
		return (NULL);
	str_join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str_join)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str_join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str_join[i++] = s2[j++];
	}
	str_join[i] = '\0';
	return (str_join);
}
/*
int	main(void)
{
	char	*s1;
	char	*s2;
	char	*result;

	// Cas de test 1 : Chaînes de caractères normales
	s1 = "Hello, ";
	s2 = "World!";
	result = ft_strjoin(s1, s2);
	if (result)
	{
		printf("Test 1 - Result: %s\n", result);
		free(result); // N'oubliez pas de libérer la mémoire allouée
	}
	else
	{
		printf("Test 1 - Allocation failed\n");
	}
	// Cas de test 2 : Une chaîne vide et une chaîne normale
	s1 = "";
	s2 = "World!";
	result = ft_strjoin(s1, s2);
	if (result)
	{
		printf("Test 2 - Result: %s\n", result);
		free(result);
	}
	else
	{
		printf("Test 2 - Allocation failed\n");
	}
	// Cas de test 3 : Deux chaînes vides
	s1 = "";
	s2 = "";
	result = ft_strjoin(s1, s2);
	if (result)
	{
		printf("Test 3 - Result: %s\n", result);
		free(result);
	}
	else
	{
		printf("Test 3 - Allocation failed\n");
	}
	// Cas de test 4 : Chaînes avec caractères spéciaux
	s1 = "Foo\n";
	s2 = "Bar\tBaz";
	result = ft_strjoin(s1, s2);
	if (result)
	{
		printf("Test 4 - Result: %s\n", result);
		free(result);
	}
	else
	{
		printf("Test 4 - Allocation failed\n");
	}
	return (0);
}
*/