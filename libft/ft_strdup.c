/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 20:21:05 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/22 12:43:13 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	int		len_s;

	len_s = 0;
	while (s[len_s])
	{
		len_s++;
	}
	duplicate = (char *)malloc(sizeof(char) * len_s + 1);
	if (!duplicate)
		return (NULL);
	len_s = 0;
	while (s[len_s])
	{
		duplicate[len_s] = s[len_s];
		len_s++;
	}
	duplicate[len_s] = '\0';
	return (duplicate);
}
