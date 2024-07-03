/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:28:14 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/22 15:09:54 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - (size_t)start)
		len = ft_strlen(s) - (size_t)start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	*s;
	char	*result;

	s = "Hello, World!";
	unsigned int start = 7; // Commence à l'index 7 ("W")
	size_t len = 5;         // Copie 5 caractères à partir de l'index 7
	// Appel de ft_substr
	result = ft_substr(s, start, len);
	if (result)
	{
		printf("Substr Result: %s\n", result);
		free(result); // Libération de la mémoire allouée pour result
	}
	else
	{
		printf("Substring extraction failed.\n");
	}
	return (0);
}
*/