/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:21:58 by jcohen            #+#    #+#             */
/*   Updated: 2024/06/25 16:36:27 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
Recoit les signaux SIGUSR1 et SIGUSR2 de client.c et les affiche
SIGUSR1 = 1
SIGUSR2 = 0
*/

void	ft_afficher_str(int sig)
{
	static char	c = 0;
	static int	i = 0;

	c += (sig == SIGUSR1) << i;
	i++;
	if (i == 8)
	{
		if (c == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: [%d]\n", getpid());
	signal(SIGUSR1, ft_afficher_str);
	signal(SIGUSR2, ft_afficher_str);
	while (1)
		pause();
	return (0);
}
