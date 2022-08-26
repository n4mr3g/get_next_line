# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpiccion <gpiccion@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 13:36:35 by gpiccion          #+#    #+#              #
#    Updated: 2022/04/20 14:24:24 by gpiccion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############## VARIABLES ##############

NAME 		= get_next_line.a
CC			= cc
BUFFER_SIZE = 42
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)
SRC			= get_next_line.c get_next_line_utils.c
OBJ			= $(SRC:.c=.o)


############## RULES ##############

all: $(NAME)

$(NAME): $(OBJ) 
		ar rcs $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CFLAGS) -c $^ -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re