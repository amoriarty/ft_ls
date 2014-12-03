/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 13:01:19 by alegent           #+#    #+#             */
/*   Updated: 2014/12/03 16:43:43 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
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
# define EOL '\n'
# define OPT '-'

/*
** Fonction d'affichage d'erreur.
*/

void				ft_error(char *error, char *file);

/*
** Fonction de gestions des options.
*/

t_opt				*init_opt(void);
int					manage_opt(t_opt *option, char **av);

/*
** Fonction de recuperation et de decoupage de temps.
*/

t_time				*init_time(t_time **my_time);
t_time				*time_info(time_t *clock, t_time **my_time);

/*
** Fonctions d'affichage.
*/

void				print_perm(mode_t info);
void				print_usr(uid_t usr, gid_t gr, t_dlist *list);
void				print_time(t_time *info);
void				print_long(t_dlist *list);

/*
** Fonctions de calcul de taille afin d'effecture le recalibrage
** de l'affichage au format long.
*/

size_t				len_nlink(t_dlist *list);
size_t				len_size(t_dlist *list);
size_t				len_usr(t_dlist *list);
size_t				len_grp(t_dlist *list);
void				print_total(t_dlist *list);

/*
** Fonctions de gestions des listes doublements chainee.
*/

t_dlist				*new_list(void);
t_dlist				*append(t_dlist *list, char *name);
t_dlist				*prepend(t_dlist *list, char *name);

/*
** Fonction(s) de lecture du dossier.
*/

int					lecture(char *dir_name, t_opt *option);

/*
** Fonctions annexes.
*/

int					is_hidden(char *name);
size_t				digitlen(int n);

#endif
