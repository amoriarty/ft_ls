# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 18:51:25 by alegent           #+#    #+#              #
#    Updated: 2014/11/29 09:32:46 by alegent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_ls

SRCS= srcs/main.c \
	  srcs/option.c \
	  srcs/error.c \
	  srcs/time.c \
	  srcs/print.c \
	  srcs/lecture.c

OBJT= main.o \
	  option.o \
	  error.o \
	  time.o \
	  print.o \
	  lecture.o

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
