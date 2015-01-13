/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 09:16:50 by alegent           #+#    #+#             */
/*   Updated: 2015/01/13 10:32:25 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>
# include "libft.h"
# include "struct.h"
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define SUCCESS 1
# define FAILURE 0
# define BUFF_SIZE 32
# define EOL '\n'
# define OPT '-'
# define CYAN "\033[1;36m"
# define RED "\033[0;31;40m"
# define PURPLE "\033[0;35;40m"
# define B_BLUE "\033[0;34;46m"
# define B_YELLOW "\033[0;34;43m"
# define CANCEL "\033[0;m"

int				current_dir(char *dir);
int				is_hidden(char *name);
int				is_complet(char *path);
size_t			ft_digitlen(int n);
t_node			*new_node(char *name, char *path);
t_opt			*init_opt(void);
t_opt			*manage_opt(char **av, int *x);
int				reading(t_opt *opt, char *dir_name);
void			print(t_node *list, t_opt *opt);
t_time			*init_time(void);
t_time			*get_time(time_t *clock);
void			print_time(t_stat *info);
void			print_long(t_node *list, t_opt *opt);
void			print_perm(mode_t info);
void			print_usr(t_stat *info, t_len *len);
t_len			*init_len(void);
void			calibration(size_t max);
t_len			*len_calcul(t_node *list);
void			putcolor(char *str, char *color);
void			print_color(char *str, t_stat *info);
void			print_link(char *path);
void			print_total(t_node *list);
void			print_major(t_stat *info, t_len *len);
t_node			*insert_node(t_node *list, t_node *new, t_opt *opt);

#endif
