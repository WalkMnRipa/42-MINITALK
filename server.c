/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:21:58 by jcohen            #+#    #+#             */
/*   Updated: 2024/07/06 22:17:49 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handle_char(unsigned char c)
{
	static char		buffer[1024];
	static size_t	buffer_index = 0;

	if (c == '\0')
	{
		write(1, buffer, buffer_index);
		write(1, "\n", 1);
		buffer_index = 0;
	}
	else
	{
		buffer[buffer_index++] = c;
		if (buffer_index == sizeof(buffer) - 1)
		{
			write(1, buffer, buffer_index);
			buffer_index = 0;
		}
	}
}

void	ft_handler_serv(int sig, siginfo_t *info, void *unused)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;

	(void)unused;
	c |= (sig == SIGUSR1) << bit_count;
	bit_count++;
	if (bit_count == 8)
	{
		ft_handle_char(c);
		bit_count = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1); // Acknowledge receipt
}

int	main(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_sigaction = ft_handler_serv;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) == -1 || sigaction(SIGUSR2, &act,
			NULL) == -1)
	{
		ft_printf("Error: sigaction failed\n");
		return (1);
	}
	ft_printf("SERVER PID: [%d]\n", getpid());
	while (1)
		pause();
	return (0);
}
