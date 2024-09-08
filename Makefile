# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 16:58:24 by jcohen            #+#    #+#              #
#    Updated: 2024/09/08 17:39:46 by jcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKE = make -C

OBJ_DIR = obj

SRCS = server.c client.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

LDFLAGS = -L$(LIBFT_DIR) -lft

RM = rm -rf

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(LIBFT) $(PRINTF) server client

$(LIBFT):
	$(MAKE) $(LIBFT_DIR)

server: $(OBJ_DIR)/server.o $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

client: $(OBJ_DIR)/client.o $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)
	
bonus: all

clean:
	$(RM) $(OBJS)
	$(MAKE) $(LIBFT_DIR) clean

fclean: clean
	$(RM) server client
	$(MAKE) $(LIBFT_DIR) fclean
	$(RM) $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
