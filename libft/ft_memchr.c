/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:26:36 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/22 13:12:33 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	size_t			i;

	source = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (source[i] == (unsigned char)c)
			return ((void *)&source[i]);
		i++;
	}
	return (NULL);
}
