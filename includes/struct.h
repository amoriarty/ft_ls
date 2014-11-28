/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 12:59:53 by alegent           #+#    #+#             */
/*   Updated: 2014/11/28 09:36:30 by alegent          ###   ########.fr       */
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
	unsigned int				opt_l;
	unsigned int				opt_rec;
	unsigned int				opt_a;
	unsigned int				opt_r;
	unsigned int				opt_t;
};

#endif
