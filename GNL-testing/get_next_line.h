/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 18:06:04 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/16 14:13:50 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_byt
{
	ssize_t dest;
	ssize_t read;
	int		nl;
}				t_byt;

int				get_next_line(const int fd, char **line);

#endif
