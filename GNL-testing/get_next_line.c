/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 18:04:22 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/16 14:09:53 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static	void	decide_push(void *buf, t_list **dest, t_list **save, t_byt *byt)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char*)buf;
	while (i < byt->read)
	{
		if (*ptr == '\n')
			byt->nl = 1;
		ft_lstpushfront(ptr, dest, 1);
		byt->dest++;
		ptr++;
		i++;
		if (byt->nl == 1)
			break ;
	}
	if (i < byt->read)
		ft_lstpushfront(ptr, save, byt->read - i);
}

static	void	load_string(t_list **dest, char **line, t_byt *byt)
{
	t_list		*trail;
	char		*ptr;

	*line = ft_strnew(byt->dest);
	if (*(char*)(*dest)->content == '\n')
	{
		byt->dest--;
		trail = (*dest)->next;
		free((*dest)->content);
		free(*dest);
		*dest = trail;
	}
	ptr = *line + (byt->dest - 1);
	trail = *dest;
	while (*dest && byt->dest)
	{
		*ptr = *(char*)(*dest)->content;
		ptr = ptr - 1;
		*dest = (*dest)->next;
		free(trail->content);
		free(trail);
		trail = *dest;
		byt->dest--;
	}
}

static	void	read_backup(t_list **dest, t_list **backup, t_byt *byt)
{
	char	*ptr;
	char	*new_backup;

	ptr = (char *)(*backup)->content;
	while ((*backup)->content_size > 0)
	{
		if (*ptr == '\n')
			byt->nl = 1;
		ft_lstpushfront(ptr, dest, 1);
		((*backup)->content_size)--;
		ptr++;
		byt->dest++;
		if (byt->nl == 1)
			break ;
	}
	if ((*backup)->content_size == 0)
	{
		ft_lstdelone(backup, &ft_del);
		return ;
	}
	new_backup = ft_memdup(ptr, ((*backup)->content_size));
	ft_memdel(&((*backup)->content));
	(*backup)->content = new_backup;
}

static	void	read_buff(const int fd, t_list **d, t_list **b, t_byt *byt)
{
	char	*buf;

	byt->read = BUFF_SIZE;
	while (byt->read != 0 && !*b && byt->nl == 0)
	{
		buf = ft_strnew(BUFF_SIZE);
		byt->read = read(fd, buf, BUFF_SIZE);
		if (byt->read < 0)
		{
			ft_strdel(&buf);
			break ;
		}
		decide_push(buf, d, b, byt);
		ft_strdel(&buf);
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*backup;
	t_list			*dest;
	t_byt			bytes;

	bytes.nl = 0;
	bytes.dest = 0;
	if (fd < 0 || !line || BUFF_SIZE == 0)
		return (-1);
	dest = NULL;
	if (backup)
		read_backup(&dest, &backup, &bytes);
	if (bytes.nl == 1 || backup)
	{
		load_string(&dest, line, &bytes);
		return (1);
	}
	read_buff(fd, &dest, &backup, &bytes);
	if (bytes.read < 0)
		return (-1);
	if (bytes.dest == 0 && !backup)
		return (0);
	load_string(&dest, line, &bytes);
	return (1);
}
