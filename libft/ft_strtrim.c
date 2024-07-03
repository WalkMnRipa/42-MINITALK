/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:09:01 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/22 19:09:21 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_set(char const *set, char character)
{
	size_t	a;

	a = 0;
	while (set[a] != '\0')
	{
		if (set[a] == character)
			return (1);
		a++;
	}
	return (0);
}

int	find_index(char const *s1, char const *set)
{
	int	index;

	index = 0;
	while (ft_is_set(set, s1[index]) == 1)
		index++;
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = find_index(s1, set);
	if (start == (int)ft_strlen(s1))
	{
		trimmed = ft_strdup("");
		return (trimmed);
	}
	end = ft_strlen(s1) - 1;
	while (ft_is_set(set, s1[end]) == 1)
		end--;
	trimmed = (char *)malloc(end - start + 2);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start <= end)
		trimmed[i++] = s1[start++];
	trimmed[i] = '\0';
	return (trimmed);
}
