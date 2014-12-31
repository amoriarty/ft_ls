/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 13:21:43 by alegent           #+#    #+#             */
/*   Updated: 2014/12/31 13:27:34 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_total(t_node *list)
{
	int				total;
	t_node			*tmp;

	total = 0;
	tmp = list;
	while (tmp)
	{
		total += tmp->info->st_blocks;
		tmp = tmp->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar(EOL);
}
