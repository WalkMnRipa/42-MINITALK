/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:58:18 by jcohen            #+#    #+#             */
/*   Updated: 2024/07/08 15:56:12 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_signal_received = 0;

void	ft_handler(int signo, siginfo_t *siginfo, void *unused)
{
	(void)signo;
	(void)siginfo;
	(void)unused;
	g_signal_received = 1;
}

void ft_send_char(int pid, unsigned char c)
{
	int bit = 0;
	while (bit < 8)
	{
		g_signal_received = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_signal_received)
			usleep(100);
		bit++;
	}
}

void	send_message(int pid, const char *msg)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &act, NULL);
	while (*msg)
	{
		ft_send_char(pid, *msg);
		msg++;
	}
	ft_send_char(pid, '\0');
	ft_printf("-------- MESSAGE SENT --------\n");
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s [PID] [MESSAGE]\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID.\n");
		return (1);
	}
	send_message(pid, argv[2]);
	return (0);
}
