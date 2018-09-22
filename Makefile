# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mntumba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/22 08:08:04 by mntumba           #+#    #+#              #
#    Updated: 2018/09/22 08:08:15 by mntumba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

SRC = filler.c\
	  game_algo.c\
	  libft/lib1.c \
	  libft/lib2.c \
	  libft/get_next_line.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.phonie: re fclean all
