/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:46:35 by jcohen            #+#    #+#             */
/*   Updated: 2024/06/04 17:06:24 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*bloc;
	size_t	i;

	if (size > 0 && num > SIZE_MAX / size)
		return (NULL);
	i = 0;
	bloc = malloc(num * size);
	if (!bloc)
		return (NULL);
	while (((char *)bloc)[i])
	{
		((char *)bloc)[i] = 0;
		i++;
	}
	return (bloc);
}
