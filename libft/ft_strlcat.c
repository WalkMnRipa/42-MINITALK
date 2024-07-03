/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:28:06 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/21 11:37:44 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	counter_src;
	size_t	len_dest;
	size_t	len_src;

	len_dest = 0;
	while (dst[len_dest] != '\0')
		len_dest++;
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (size <= len_dest)
		return (len_src + size);
	else
	{
		counter_src = 0;
		while (src[counter_src] != '\0' && (len_dest + counter_src) < size - 1)
		{
			dst[len_dest + counter_src] = src[counter_src];
			counter_src++;
		}
	}
	dst[len_dest + counter_src] = '\0';
	return (len_dest + len_src);
}
/*
int	main(void)
{
	char		dest[20] = "Hello, ";
	const char	*src = "world!";
	size_t		size;
	size_t		result;

	size = sizeof(dest);
	result = strlcat(dest, src, size);
	printf("Result: %s\n", dest);
	printf("Total length: %zu\n", result);
	return (0);
}
*/