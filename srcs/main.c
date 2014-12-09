/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 18:56:30 by alegent           #+#    #+#             */
/*   Updated: 2014/12/09 10:06:01 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					main(int ac, char **av)
{
	t_opt			option;
	time_t			current;

	current = time(NULL);
	if (ac == 3)
	{
		manage_opt(&option, av);
		lecture(av[2], &option, &current);
	}
	else if (ac == 1)
		lecture(".", init_opt(), &current);
	else
		ft_putendl("usage: ft_ls option chemin (temporairement)");
	return (42);
}
