/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 18:56:30 by alegent           #+#    #+#             */
/*   Updated: 2014/12/09 14:16:42 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					main(int ac, char **av)
{
	t_opt			option;
	time_t			current;
	int				x;

	current = time(NULL);
	if (ac == 1)
		lecture(".", init_opt(), &current);
	else
	{
		x = manage_opt(&option, av) - 1;
		while (x++ < ac - 1)
			if (lecture(av[x], &option, &current) == ERROR)
				put_error(av[x]);
	}
	return (42);
}
