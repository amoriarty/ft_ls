/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 09:21:27 by alegent           #+#    #+#             */
/*   Updated: 2015/01/08 12:39:45 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_node			*list_reg(t_node *list, t_opt *opt)
{
	t_node			*tmp;
	t_node			*prec;
	t_node			*new;
	t_node			*reg;

	tmp = list;
	prec = list;
	reg = NULL;
	while (tmp)
	{
		if (S_ISREG(tmp->info->st_mode))
		{
			new = new_node(tmp->name, tmp->path);
			reg = insert_node(reg, new, opt);
			prec->next = tmp->next;
		}
		prec = prec->next;
		tmp = tmp->next;
	}
	if (reg)
		print_long(reg, opt);
	return (list);
}

static void			readall(t_node *list, t_opt *opt)
{
	int				yes;
	t_node			*tmp;

	yes = FALSE;
	tmp = list;
	while (tmp)
	{
		yes = (tmp->next) ? TRUE : yes;
		if (yes == TRUE && (S_ISDIR(tmp->info->st_mode)))
		{
			ft_putstr(tmp->name);
			ft_putendl(":");
		}
		reading(opt, tmp->name);
		ft_putchar(EOL);
		tmp = tmp->next;
	}
}

static void			get_read(int ac, char **av)
{
	int				x;
	t_opt			*opt;
	t_node			*list;
	t_node			*new;

	x = 1;
	opt = manage_opt(av);
	while (x < ac)
	{
		if (ft_strchr(av[x], OPT) == NULL || (av[x][0] == OPT && !av[x][1]))
		{
			new = new_node(av[x], ".");
			list = insert_node(list, new, init_opt());
		}
		x++;
	}
	if (list != NULL)
	{
		list = list_reg(list, opt);
		readall(list, opt);
	}
	else
		reading(opt, ".");
}

int					main(int ac, char **av)
{
	if (ac == 1)
	{
		reading(init_opt(), ".");
		return (EXIT_SUCCESS);
	}
	if (ac > 1)
	{
		get_read(ac, av);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
