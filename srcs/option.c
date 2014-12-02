/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:01:05 by alegent           #+#    #+#             */
/*   Updated: 2014/12/02 13:22:44 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt				*init_opt(void)
{
	t_opt			*option;

	option = (t_opt *)malloc(sizeof(t_opt));
	option->opt_l = FALSE;
	option->opt_rec = FALSE;
	option->opt_a = FALSE;
	option->opt_t = FALSE;
	option->opt_r = FALSE;
	return (option);
}

static int			illegal(char *av)
{
	int				x;

	x = 0;
	while (av[++x])
	{
		if (av[x] != 'l' && av[x] != 'R' && av[x] != 'a'
				&& av[x] != 'r' && av[x] != 't' && av[x] != OPT)
			return (TRUE);
	}
	return (FALSE);
}

static void			get_opt(t_opt *option, char *av)
{
	option->opt_l = (ft_strchr(av, 'l')) ? TRUE : option->opt_l;
	option->opt_rec = (ft_strchr(av, 'R')) ? TRUE : option->opt_rec;
	option->opt_a = (ft_strchr(av, 'a')) ? TRUE : option->opt_a;
	option->opt_r = (ft_strchr(av, 'r')) ? TRUE : option->opt_r;
	option->opt_t = (ft_strchr(av, 't')) ? TRUE : option->opt_t;
}

int					manage_opt(t_opt *option, char **av)
{
	int				x;
	int				yes;

	x = 0;
	yes = FALSE;
	while (av[x])
	{
		if (ft_strchr(av[x], OPT) != NULL)
		{
			get_opt(option, av[x]);
			if (illegal(av[x]) == TRUE)
				ft_error("illegal option -- ", av[x]);
			yes = TRUE;
		}
		x++;
	}
	return (yes);
}
