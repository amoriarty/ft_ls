# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 18:51:25 by alegent           #+#    #+#              #
#    Updated: 2014/11/27 12:25:49 by alegent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_ls

SRCS= srcs/main.c

OBJT= main.o

GCC= gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	make -C libft/ clean
	$(GCC) -c $(SRCS) -I libft/includes -I includes
	$(GCC) $(OBJT) -I libft/includes -I includes -L libft/ -lft -o $(NAME)

clean:
	rm -f $(OBJT)

fclean:
	rm -f $(NAME)

re: fclean clean $(NAME)

.PHONY: clean fclean
