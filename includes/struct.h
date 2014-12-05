/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 12:59:53 by alegent           #+#    #+#             */
/*   Updated: 2014/12/05 16:26:01 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
** Typedef des structures existantes.
*/

typedef struct dirent			t_dirent;
typedef struct stat				t_stat;
typedef struct group			t_group;
typedef struct passwd			t_passwd;

/*
** Structure de temps personelle.
*/

typedef struct s_time			t_time;
struct							s_time
{
	char						*complet;
	char						*month;
	char						*day;
	char						*hour;
	char						*minute;
	char						*second;
	char						*year;
};

/*
** Structure permettant la gestion des options.
*/

typedef struct s_opt			t_opt;
struct							s_opt
{
	unsigned int				m_path;
	unsigned int				opt_l;
	unsigned int				opt_rec;
	unsigned int				opt_a;
	unsigned int				opt_r;
	unsigned int				opt_t;
	unsigned int				opt_s;
};

/*
** Structure type liste doublement chainee permettant le tri de chaque entrer
** renvoyer par readdir.
*/

typedef struct s_entry			t_entry;
struct							s_entry
{
	char						*name;
	char						*path;
	t_stat						*info;
	t_entry						*next;
	t_entry						*prec;
};

typedef struct s_dlist			t_dlist;
struct							s_dlist
{
	size_t						lenght;
	t_entry						*begin;
	t_entry						*end;
};

#endif
