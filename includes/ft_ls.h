/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 13:01:19 by alegent           #+#    #+#             */
/*   Updated: 2014/11/29 10:10:28 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
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
void				print_usr(uid_t usr, gid_t gr);
void				print_time(t_time *info);
void				print_global(t_stat *info, char *name);

/*
** Fonction(s) de lecture du dossier.
*/

int					lecture(char *dir_name, t_opt *option);

#endif
