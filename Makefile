# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 16:58:24 by jcohen            #+#    #+#              #
#    Updated: 2024/06/26 12:50:56 by jcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE = make -C

OBJ_DIR = obj

SRCS = server.c client.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ../ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

LDFLAGS = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

RM = rm -rf

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(LIBFT) $(PRINTF) server client

$(LIBFT):
	$(MAKE) $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) $(PRINTF_DIR)

server: $(OBJ_DIR)/server.o $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

client: $(OBJ_DIR)/client.o $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(MAKE) $(LIBFT_DIR) clean
	$(MAKE) $(PRINTF_DIR) clean

fclean: clean
	$(RM) server client
	$(MAKE) $(LIBFT_DIR) fclean
	$(MAKE) $(PRINTF_DIR) fclean
	$(RM) $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
