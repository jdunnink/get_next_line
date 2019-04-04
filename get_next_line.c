/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 18:04:22 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/04 15:20:27 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*dest;
	size_t	destlen;

	if (!s1 || !s2)
	{
		printf("signal\n");
		return (NULL);
	}
	dest = NULL;
	destlen = ft_strlen(s1) + len;
	if (s1 && s2)
	{
		dest = (char*)malloc(sizeof(char) * (destlen + 1));
		if (!dest)
			return (NULL);
		ft_strcpy(dest, s1);
		ft_strncat(dest, s2, len);
	}
	return (dest);
}

static char *add_line(char *buf, char **line)
{
	size_t i;
	char *new;

	i = 0;
	while(buf[i] != '\n' && buf[i] != '\0')
		i++;
	if(!*line)
		new = ft_strsub(buf, 0, i);
	else
	{
		new = ft_strnjoin(*line, buf, i);
	}
	return (new);
}

int	get_next_line(int fd, char **line)
{
	ssize_t bytes;
	char	*buf;
	char	*new;

	if (*line)
		ft_strdel(line);
	bytes = 1;
	buf = ft_memalloc(BUFF_SIZE);
	while (bytes != 0)
	{
		bytes = read(fd, buf, BUFF_SIZE);
		if (ft_memchr(buf, '\n', bytes) == 0)
		{
			*line  = add_line(buf, line);
		}
		else
		{
			new = add_line(buf, line);
			free(*line);
			line = &new;
			break;
		}
	}
	return (0);
}
