/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:36:02 by alegent           #+#    #+#             */
/*   Updated: 2014/11/28 15:39:49 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <time.h>
#include "libft.h"
#include "ft_ls.h"
#include "struct.h"

void				ft_print_time(t_time *info)
{
	ft_putstr(info->month);
	ft_putchar(' ');
	ft_putstr(info->day);
	ft_putchar(' ');
	ft_putstr(info->hour);
	ft_putchar(':');
	ft_putstr(info->minute);
	ft_putchar(' ');
}
