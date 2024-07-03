/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:30:54 by jcohen            #+#    #+#             */
/*   Updated: 2024/05/24 16:22:52 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nb_lst;

	nb_lst = 0;
	while (lst != NULL)
	{
		nb_lst++;
		lst = lst->next;
	}
	return (nb_lst);
}
