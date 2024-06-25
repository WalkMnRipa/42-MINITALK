/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:22:16 by jcohen            #+#    #+#             */
/*   Updated: 2024/06/25 16:39:23 by jcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../42-libft/libft.h"
# include "../42-printf/includes/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_send_char(int pid, char c);
void	ft_afficher_str(int sig);

#endif