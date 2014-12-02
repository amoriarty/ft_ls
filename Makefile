# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 18:51:25 by alegent           #+#    #+#              #
#    Updated: 2014/12/02 13:48:25 by alegent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_ls

SRCS= srcs/main.c \
	  srcs/option.c \
	  srcs/error.c \
	  srcs/time.c \
	  srcs/print_long.c \
	  srcs/lecture.c \
	  srcs/print_opt.c \
	  srcs/ft_annex.c \
	  srcs/list.c

OBJT= main.o \
	  option.o \
	  error.o \
	  time.o \
	  print_long.o \
	  lecture.o \
	  print_opt.o \
	  ft_annex.o \
	  list.o

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
