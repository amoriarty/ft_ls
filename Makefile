# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/26 18:51:25 by alegent           #+#    #+#              #
#    Updated: 2015/01/06 14:32:17 by alegent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_ls

SRCS= srcs/main.c \
	  srcs/current_dir.c \
	  srcs/ft_digitlen.c \
	  srcs/is_complet.c \
	  srcs/is_hidden.c \
	  srcs/new_node.c \
	  srcs/add_node.c \
	  srcs/init_opt.c \
	  srcs/manage_opt.c \
	  srcs/reading.c \
	  srcs/print.c \
	  srcs/init_time.c \
	  srcs/get_time.c \
	  srcs/print_time.c \
	  srcs/print_long.c \
	  srcs/print_perm.c \
	  srcs/print_usr.c \
	  srcs/calibration.c \
	  srcs/len_calcul.c \
	  srcs/init_len.c \
	  srcs/sort_ascii.c \
	  srcs/add_first.c \
	  srcs/putcolor.c \
	  srcs/print_color.c \
	  srcs/print_link.c \
	  srcs/print_total.c \
	  srcs/print_major.c \
	  srcs/insert_node.c \
	  srcs/free_node.c \

OBJT= main.o \
	  current_dir.o \
	  ft_digitlen.o \
	  is_complet.o \
	  is_hidden.o \
	  new_node.o \
	  add_node.o \
	  init_opt.o \
	  manage_opt.o \
	  reading.o \
	  print.o \
	  init_time.o \
	  get_time.o \
	  print_time.o \
	  print_long.o \
	  print_perm.o \
	  print_usr.o \
	  calibration.o \
	  len_calcul.o \
	  init_len.o \
	  sort_ascii.o \
	  add_first.o \
	  putcolor.o \
	  print_color.o \
	  print_link.o \
	  print_total.o \
	  print_major.o \
	  insert_node.o \
	  free_node.o \

GCC= gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@make -C libft/ clean
	@$(GCC) -c $(SRCS) -I libft/includes -I includes
	@$(GCC) $(OBJT) -I libft/includes -I includes -L libft/ -lft -o $(NAME)

clean:
	@rm -f $(OBJT)

fclean:
	@rm -f $(NAME)

re: fclean clean $(NAME)

.PHONY: clean fclean
