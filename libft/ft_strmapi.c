/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:40:24 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/23 13:05:00 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*mapi;

	if (!s && !f)
		return (NULL);
	len = ft_strlen(s);
	mapi = (char *)malloc(len + 1);
	if (!mapi)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mapi[i] = (f((unsigned int)i, s[i]));
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}
