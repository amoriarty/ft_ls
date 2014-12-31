/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_major.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 15:22:10 by alegent           #+#    #+#             */
/*   Updated: 2014/12/31 15:25:06 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_major(t_stat *info, t_len *len)
{
	calibration(len->lmajor - ft_digitlen(major(info->st_rdev)));
	ft_putnbr(major(info->st_rdev));
	ft_putstr(", ");
	calibration(len->lminor - ft_digitlen(minor(info->st_rdev)));
	ft_putnbr(minor(info->st_rdev));
}
