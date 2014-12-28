/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 09:48:28 by alegent           #+#    #+#             */
/*   Updated: 2014/12/17 10:03:31 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt				*manage_opt(char **av)
{
	int				i;
	t_opt			*opt;

	i = 1;
	opt = init_opt();
	while (av[i] && ft_strchr(av[i], OPT))
	{
		if (ft_strchr(av[i], OPT))
		{
			opt->l = (ft_strchr(av[i], 'l')) ? TRUE : opt->l;
			opt->rec = (ft_strchr(av[i], 'R')) ? TRUE : opt->rec;
			opt->r = (ft_strchr(av[i], 'r')) ? TRUE : opt->r;
			opt->a = (ft_strchr(av[i], 'a')) ? TRUE : opt->a;
			opt->t = (ft_strchr(av[i], 't')) ? TRUE : opt->t;
		}
		i++;
	}
	return (opt);
}
