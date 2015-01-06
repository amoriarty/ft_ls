/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 09:48:28 by alegent           #+#    #+#             */
/*   Updated: 2015/01/06 16:49:23 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			illegal(char *av)
{
	int				i;

	i = 0;
	while (i <= 300)
	{
		if (ft_strchr(av, i) && i != 'l' && i != 'r' && i != 'R' && i != 'a'
				&& i != 't' && ft_isalnum(i))
		{
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(i);
			ft_putchar(EOL);
			ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
			exit(EXIT_FAILURE);
		}
		i++;
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
		if (ft_strchr(av[i], OPT) && av[i][1])
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
