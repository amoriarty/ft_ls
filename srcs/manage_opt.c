/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 09:48:28 by alegent           #+#    #+#             */
/*   Updated: 2014/12/28 16:13:52 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			illegal(char *av)
{
	if (ft_strchr(av, 'l') == NULL && ft_strchr(av, 'R') == NULL
			&& ft_strchr(av, 'r') == NULL && ft_strchr(av, 'a') == NULL
			&& ft_strchr(av, 't') == NULL)
	{
		ft_putstr("ft_ls : illegal option -- ");
		ft_putendl(ft_strchr(av, OPT) + 1);
		ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
		exit(EXIT_FAILURE);
	}
}

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
			illegal(av[i]);
		}
		i++;
	}
	return (opt);
}
