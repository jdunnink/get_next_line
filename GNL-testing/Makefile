#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jdunnink <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/04 15:34:03 by jdunnink      #+#    #+#                  #
#    Updated: 2019/04/17 11:15:54 by jdunnink      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = test

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang -o test main.c -I libft/includes -L libft/ -lft

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all