/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 09:59:03 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/05 11:40:28 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*x;
	size_t			i;

	x = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		x[i] = c;
		i++;
	}
	return (b);
}

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = (void*)malloc(size);
	if (ptr)
	{
		ft_memset(ptr, 0, size);
		return (ptr);
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;
	int		len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (dest)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (0);
}

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

char	*ft_strnew(size_t size)
{
	char *ptr;

	ptr = (char*)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', size + 1);
	return (ptr);
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	node = (t_list*)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	if (content)
	{
		node->content = ft_memalloc(content_size);
		node->content = ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	else
	{
		node->content = NULL;
		node->content_size = 0;
	}
	node->next = NULL;
	return (node);
}

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	ft_push_front(void const *content, t_list **alst, size_t content_size)
{
	if (alst != NULL && content != NULL)
	{
		if(!*alst)
			*alst = ft_lstnew(content, content_size);
		else
			ft_lstadd(alst, ft_lstnew(content, content_size));
	}
}

static ssize_t push_decider(void *buf, t_list **dest, t_list** backup, ssize_t bytes)
{
	int i;
	int nl_c;
	unsigned char *ptr;
	ssize_t total;

	ptr = (unsigned char*)buf;
	nl_c = 0;
	i = 0;
	total = 0;
	while (i < bytes)
	{
		if (*ptr  == '\n')
			nl_c++;	
		if(nl_c == 0)
			ft_push_front(ptr, dest, 1);
		else
		{
			if (nl_c == 1 && !*backup)
				total = i;
			ft_push_front(ptr, backup, 1);
		}
		i++;
		ptr++;
	}
	if (nl_c == 0)
		return (i);
	return (total);
}

static void load_string(t_list **dest, char **line, ssize_t total)
{
	char *back;
	t_list *start;

	start = *dest;
	if(*line)
		ft_strdel(line);
	*line = ft_strnew(total - 1);
	total--;
	back = *line+total;
	if (*(char*)(*dest)->content == '\n')
	{
		*dest = (*dest)->next;
		free(start->content);
		free(start);
		start = *dest;
	}
	while(*dest)
	{
		*back = *(char*)(*dest)->content;
		*dest = (*dest)->next;
		free(start->content);
		free(start);
		start = *dest;
		back = back - 1;
	}
}

// if a second newline is encountered or a newline is the last node in the list,
// the backuplist should not be freed, aand
// dest should be loaded immediatly.

// else, load the entire backup into the dest string and proceed as usual.

static ssize_t switch_list(t_list **dest, t_list **backup)
{
	t_list *iter;
	t_list *begin;
	ssize_t bytes;

	bytes = 0;
	begin = *backup;
	iter = *backup;
	while (iter)
	{
		bytes++;
		if (*(char *)iter->content == '\n')
			break;
		iter = iter->next;
	}
	*backup = iter->next;
	iter->next = *dest;
	*dest = begin;
	return (bytes);
}

int main(void)
{
	void *buf = "This is the line";
	void *buf2 = " to be given back. This seems to be working.\nsdifsdf";
	ssize_t total;
	total = 0;

	t_list *dest;
	static t_list *backup;

	size_t bytes;
	size_t bytes2;
	bytes = strlen(buf);
	bytes2 = strlen(buf2);

	char *new_line = ft_strdup("This is the previous line.");

	total += push_decider(buf, &dest, &backup, bytes);
	total += push_decider(buf2, &dest, &backup, bytes2);
	total += switch_list(&dest, &backup);
	load_string(&dest, &new_line, total);
	printf("%s\n", new_line);
	return (0);
}