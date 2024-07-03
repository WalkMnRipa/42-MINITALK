/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:58:18 by jcohen            #+#    #+#             */
/*   Updated: 2024/07/03 17:22:56 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
Envoyer des signaux SIGUSR1 et SIGUSR2 au serveur
SIGUSR1 = 1
SIGUSR2 = 0
*/

void	ft_handler(int signo, siginfo_t *siginfo, void *unused)
{
	(void)unused;
	(void)siginfo;
	(void)signo;
}

void	ft_bit_by_bit(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		usleep(100);
		bit++;
	}
}

void	send_bit(int pid, char *msg)
{
	struct sigaction	act;
	siginfo_t			siginfo;
	int					i;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &ft_handler;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, 0);
	siginfo.si_pid = pid;
	i = 0;
	while (msg[i] != '\0')
	{
		ft_bit_by_bit(pid, msg[i++]);
	}
	ft_printf("-----MESSAGE SENT-----\n");
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("WRONG FORMAT.\nUsage: ./client [PID] [MESSAGE]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1)
	{
		ft_printf("INVALID PID.\n");
		return (1);
	}
	send_bit(pid, argv[2]);
	return (0);
}
