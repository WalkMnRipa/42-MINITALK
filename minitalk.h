/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:22:16 by jcohen            #+#    #+#             */
/*   Updated: 2024/07/03 17:23:10 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./ft_printf/includes/ft_printf.h"
# include "./libft/libft.h"
# include <signal.h>
# include <unistd.h>

void	ft_handler(int sig, siginfo_t *info, void *unused);
void	ft_bit_by_bit(int pid, char c);
void	send_bit(int pid, char *msg);
void	ft_handler_serv(int sig, siginfo_t *info, void *unused);

#endif