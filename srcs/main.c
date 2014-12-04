/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 18:56:30 by alegent           #+#    #+#             */
/*   Updated: 2014/12/04 16:01:54 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					main(int ac, char **av)
{
	t_opt			option;

	if (ac == 3)
	{
		manage_opt(&option, av);
		lecture(av[2], &option);
	}
	else if (ac == 1)
		lecture(".", NULL);
	else
		ft_putendl("usage: ft_ls option chemin (temporairement)");
	return (42);
}
