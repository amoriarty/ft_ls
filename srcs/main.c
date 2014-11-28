/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 18:56:30 by alegent           #+#    #+#             */
/*   Updated: 2014/11/28 10:47:13 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include "struct.h"

int					main(int ac, char **av)
{
	t_opt			*option;

	option = init_opt();
	if (ac > 1)
	{
		manage_opt(option, av);
		ft_putnbr(option->opt_rec);
		ft_putchar(EOL);
		ft_putnbr(option->opt_l);
		ft_putchar(EOL);
	}
	return (42);
}
