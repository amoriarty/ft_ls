/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 13:01:19 by alegent           #+#    #+#             */
/*   Updated: 2014/12/11 18:34:54 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdio.h>
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
# define RED "\033[31m"
# define BLUE "\033[34m"
# define CYAN "\033[1;36m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define CANCEL "\033[00m"
# define BACKCOLOR "\033[43"

/*
** Fonction d'affichage d'erreur.
*/

void				put_error(char *path);
void				illegal_error(char *option);

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
int					is_early(time_t *clock, time_t *current);

/*
** Fonctions d'affichage.
** La fonction file type n'est pas dans le meme fichier mais il me parait
** plus judicieux de l'ecrire ici.
*/

void				file_type(mode_t info);
void				print_perm(mode_t info);
void				print_usr(uid_t usr, gid_t gr, t_dlist *list);
void				print_time(t_time *info, time_t *clock, time_t *current);
void				print_total(t_dlist *list);
void				print_long(t_entry *tmp, t_dlist *list, time_t *clock);
void				print(t_dlist *list, t_opt *option, time_t *clock);

/*
** Fonctions de calcul de taille afin d'effecture le recalibrage
** de l'affichage au format long.
*/

size_t				len_nlink(t_dlist *list);
size_t				len_size(t_dlist *list);
size_t				len_usr(t_dlist *list);
size_t				len_grp(t_dlist *list);

/*
** Fonctions de gestions des listes doublements chainee.
*/

t_dlist				*new_list(void);
t_dlist				*append(t_dlist *list, char *name, char *path);
t_dlist				*prepend(t_dlist *list, char *name, char *path);
t_dlist				*list_tri(t_dlist *list, char *name, char *path);

/*
** Fonction(s) de lecture du dossier.
*/

int					lecture(char *dir_name, t_opt *option, time_t *clock);

/*
** Fonctions annexes.
*/

int					is_hidden(char *name);
size_t				digitlen(int n);
t_entry				*new_entry(void);
void				putcolor(char *str, char *color);
void				colorgestion(char *str, mode_t info);

#endif
