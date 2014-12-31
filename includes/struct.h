/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 09:19:47 by alegent           #+#    #+#             */
/*   Updated: 2014/12/31 12:38:18 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct dirent			t_dirent;
typedef struct stat				t_stat;
typedef struct group			t_group;
typedef struct passwd			t_passwd;

/*
** Structure option.
*/

typedef struct s_opt			t_opt;
struct							s_opt
{
	unsigned int				l;
	unsigned int				rec;
	unsigned int				a;
	unsigned int				r;
	unsigned int				t;
};

/*
** Structure de listes.
*/

typedef struct s_node			t_node;
struct							s_node
{
	char						*name;
	char						*path;
	t_stat						*info;
	t_node						*next;
};

typedef struct s_time			t_time;
struct							s_time
{
	char						*complet;
	char						*month;
	char						*day;
	char						*hour;
	char						*minute;
	char						*second;
	char						*years;
};

typedef struct s_len			t_len;
struct							s_len
{
	size_t						nlink;
	size_t						lsize;
	size_t						usr;
	size_t						grp;
};

#endif
