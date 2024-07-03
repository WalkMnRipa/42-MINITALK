/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:28:12 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/21 11:41:37 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	i = 0;
	needle_len = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (needle[needle_len] != '\0')
		needle_len++;
	while (*haystack != '\0' && len >= needle_len)
	{
		i = 0;
		while (needle[i] != '\0' && haystack[i] == needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

/*
void	test_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*result;

	result = ft_strnstr(haystack, needle, len);
	printf("strnstr(\"%s\", \"%s\", %zu) => ", haystack, needle, len);
	if (result != NULL)
	{
		printf("Found \"%s\" at position %ld\n", needle, result - haystack);
	}
	else
	{
		printf("Not found\n");
	}
}

int	main(void)
{
	const char	*haystack = "Hello, World!";

	// Test avec une sous-chaîne présente
	test_strnstr(haystack, "World", ft_strlen(haystack));
	// Test avec len égal à la longueur de haystack
	test_strnstr(haystack, "World", 5);
	// Test avec len plus petit que la longueur de haystack
	// Test avec une sous-chaîne absente
	test_strnstr(haystack, "Universe", ft_strlen(haystack));
	test_strnstr(haystack, "Universe", 12);
	// Test avec len égal à la longueur de haystack
	// Test avec une sous-chaîne vide
	test_strnstr(haystack, "", ft_strlen(haystack));
	return (0);
}
*/