/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 13:01:19 by alegent           #+#    #+#             */
/*   Updated: 2014/11/28 10:32:29 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
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

#endif
