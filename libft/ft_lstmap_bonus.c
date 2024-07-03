/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:32:21 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/25 15:00:21 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*create_new_elem(void *content)
{
	t_list	*new_elem;

	new_elem = ft_lstnew(content);
	if (!new_elem)
		return (NULL);
	return (new_elem);
}

static void	free_map(t_list *map, void (*del)(void *))
{
	t_list	*tmp;

	while (map)
	{
		tmp = map->next;
		ft_lstdelone(map, del);
		map = tmp;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*new_elem;
	void	*transformed_content;

	if (!lst || !f || !del)
		return (NULL);
	map = NULL;
	while (lst)
	{
		transformed_content = f(lst->content);
		new_elem = create_new_elem(transformed_content);
		if (!new_elem)
		{
			del(transformed_content);
			free_map(map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, new_elem);
		lst = lst->next;
	}
	return (map);
}
