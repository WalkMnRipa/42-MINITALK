/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:21:58 by jcohen            #+#    #+#             */
/*   Updated: 2024/07/03 17:06:24 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
Recoit les signaux SIGUSR1 et SIGUSR2 de client.c et les affiche
SIGUSR1 = 1
SIGUSR2 = 0
*/

void	ft_handler_serv(int sig, siginfo_t *info, void *unused)
{
	static char	c = 0;
	static int	i = 0;

	(void)unused;
	if (sig == SIGUSR1)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		if (c == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(c, 1);
		i = 0;
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			printf("Error Signal\n");
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = &ft_handler_serv;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	if ((sigaction(SIGUSR1, &act, 0)) == -1)
		ft_printf("Error sigaction\n");
	if ((sigaction(SIGUSR2, &act, 0)) == -1)
		ft_printf("Error sigaction\n");
	ft_printf("SERVEUR ON\n");
	ft_printf("Server PID: [%d]\n", getpid());
	while (1)
		pause();
	return (0);
}
