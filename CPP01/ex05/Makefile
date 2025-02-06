# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drongier <drongier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 15:45:27 by drongier          #+#    #+#              #
#    Updated: 2025/02/03 18:28:56 by drongier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Harl.cpp

CC 		= g++

OBJ = $(SRC:.cpp=.o)

CFLAGS	= -Wall -Wextra - Werror -g -std=c++98

NAME	= harl

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re