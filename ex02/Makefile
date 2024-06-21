# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 16:43:53 by crebelo-          #+#    #+#              #
#    Updated: 2024/06/19 16:44:27 by crebelo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := account

SRC := Account.cpp \
	   tests.cpp 

OBJ := $(SRC:.cpp=.o)

CC := c++

CFLAGS := -Wall -Wextra -Werror -I./ -std=c++98

GREEN := \033[0;32m

all: $(OBJ) $(NAME)

$(OBJ): %.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(GREEN) Compiling Account ... "
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN) Done! "

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.phony: all clean fclean re
