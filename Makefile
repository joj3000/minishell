# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerbs <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 19:18:55 by jerbs             #+#    #+#              #
#    Updated: 2020/03/09 19:18:59 by jerbs            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FLAGS = -Wall -Werror -Wextra
O_FILES = O_files
C_FILES = C_files

.C = ./C_files/*.c
.O = *.o

all: $(NAME)

$(NAME):
	gcc -I./$(C_FILES) $(FLAGS) -c $(.C)
	gcc -o $(NAME) $(.O)
	mkdir -p $(O_FILES)
	@mv $(.O) $(O_FILES)

clean:
	rm -rf $(O_FILES)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: clean fclean re all
