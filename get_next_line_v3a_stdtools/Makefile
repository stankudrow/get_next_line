# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stanislav <student.21-school.ru>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 13:13:56 by stanislav         #+#    #+#              #
#    Updated: 2022/06/22 13:13:56 by stanislav        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := gnl

HDR := ft_getline.h
SRC := ft_getdelim.c ft_getline.c
OBJ := $(SRC:.c=.o)

CC := cc
CFLAGS := -Wall -Werror -Wextra -fsanitize=address -fsanitize=leak -g
RM := rm -rf

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) main.c $(OBJ) -o $(NAME)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: $(NAME)
	lldb -- ./$(NAME)
