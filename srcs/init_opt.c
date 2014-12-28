/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 09:24:08 by alegent           #+#    #+#             */
/*   Updated: 2014/12/17 09:33:49 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt				*init_opt(void)
{
	t_opt			*opt;

	if ((opt = (t_opt *)malloc(sizeof(t_opt))) == NULL)
		return (NULL);
	opt->l = FALSE;
	opt->rec = FALSE;
	opt->a = FALSE;
	opt->r = FALSE;
	opt->t = FALSE;
	return (opt);
}
