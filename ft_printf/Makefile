# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcohen <jcohen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 15:36:55 by jcohen            #+#    #+#              #
#    Updated: 2024/05/29 16:18:44 by jcohen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_DIR = srcs
INC_DIR = includes

SRCS = $(SRC_DIR)/basic_conversions.c \
	   $(SRC_DIR)/additional_conversions.c \
	   $(SRC_DIR)/hexadecimal_operations.c \
       $(SRC_DIR)/numeric_operations.c \
	   $(SRC_DIR)/output_operations.c \
	   $(SRC_DIR)/conversion_logic.c \
	   $(SRC_DIR)/ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
	$(CC) -c $(CFLAGS) -I$(INC_DIR) $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re