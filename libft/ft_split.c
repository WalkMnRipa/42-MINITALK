/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:26:46 by jcohen            #+#    #+#             */
/*   Updated: 2024/06/18 15:25:40 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_word(const char *src, char c)
{
	char	*word;
	int		i;
	int		len;

	len = 0;
	while (src[len] && !(src[len] == c))
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = src[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	count_words(const char *src, char charset)
{
	int	counter;
	int	in_word;

	counter = 0;
	in_word = 0;
	while (*src)
	{
		if (!(*src == charset) && !(in_word))
		{
			in_word = 1;
			counter++;
		}
		else if (*src == charset)
			in_word = 0;
		src++;
	}
	return (counter);
}

static int	free_all(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static int	fill_words(char const *s, char c, char **final)
{
	int	j;

	j = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s && !(*s == c))
		{
			final[j] = create_word(s, c);
			if (!final[j])
			{
				return (free_all(final, j));
			}
			j++;
		}
		while (*s && !(*s == c))
			s++;
	}
	final[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		nb_mots;
	char	**final;

	if (!s)
		return (NULL);
	nb_mots = count_words(s, c);
	final = (char **)malloc((nb_mots + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	if (!fill_words(s, c, final))
		return (NULL);
	return (final);
}
