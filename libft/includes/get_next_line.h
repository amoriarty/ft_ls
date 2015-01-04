/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 11:29:19 by alegent           #+#    #+#             */
/*   Updated: 2014/11/26 17:56:03 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define EOL '\n'
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define BUFF_SIZE 1

int		get_next_line(const int fd, char **line);

#endif
