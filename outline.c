/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   outline.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 10:12:50 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/05 18:24:42 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# define BUFF_SIZE 20										// set the macro BUFF_SIZE to mean 20.

int main(int argc, char **argv)								// function main gets called with argc - 1 number of arguments.
{
	char 	*next_line;										// variable used to store the next line for each iteration of GNL.
	char 	**line;											// pointer to the adress of next_line, send to GNL.
	int		r;												// stores the return value of GNL, 1, 0 or -1.
	int		fd;												// stores the file discriptor used to open the file to be read.

	if (argc != 2)											// if there are more or less than one argument,
		return (0);												// end the program.

	fd = open(argv[1], O_RDONLY);							// open  the first argument in read-only mode.
	

	while (r = 1)											// while reading was successful and EOF is not found,
		r = get_next_line(fd, line);								// get the next line from the file.

	close(fd);												// close the file discriptor.
	return (0);
}

int get_next_line(int fd, char **line)
{
	ssize_t			bytes;									// stores the number of bytes read from fd to the buffer.
	ssize_t			total;									// stores the number of bytes added to dest list;
	void			buf[BUFF_SIZE];							// stores the bytes read from fd to the buffer.

	t_list			**dest;									// sentinel pointer to destination list; 
	t_list			*dhead = NULL;							// head pointer to destination list;

	static t_list	**backup;								// sentinel pointer to backup list;
	static t_list	*bhead = NULL;							// head pointer to backup list;

	total = 0;
	dest = &dhead;											// point dest sentinel to head;
	if (*backup)												// if there is a backup node,	
		total += switch_list(backup, dest);						// load backup nodes into destination list, until the second newline;
	ft_lstdel(*backup);										// free the empty backup list and set pointer to NULL;
	backup = &bhead;										// point backup sentinel to head;
	bytes = BUFF_SIZE;										// initialize bytes to nonzero;
	while (bytes != 0 && !*backup)							// while the number of bytes read != zero and no backup has been created,
	{
		bytes = read(fd, buf, BUFF_SIZE);						// read BUFF_SIZE bytes from fd to the buffer.		
		if (x == 0)												// if the number of bytes read is zero,
			return (0);												// end of file is reached -> return zero to main.
		total += push_decider(buf, dest, backup, bytes)			// push the buffer into the correct lists.
	}
	load_string(dest, line, total);							// load dest list into string and free dest, frees previous line;
	return (1);												// reading has completed successfully, return one to main.
}

static ssize_t push_decider(void *buf, t_list **dest, t_list** backup, ssize_t bytes) // decides which list to push the buffer contents to.
{
	int i;											// counts the number of bytes that have been pushed.
	int nl_c;										// counts the number of newlines that have been found.
	unsigned char *ptr;								// UC pointer used to find newlines.
	ssize_t dest;

	ptr = (unsigned char*)buf;						// interpret buffer as being unsigned char.
	nl_c = 0;										// initialize newline counter
	i = 0;											// initialize byte counter
	dest = 0;										// initialize bytes to dest counter
	while (i < bytes)								// while bytes counted is less than buffer size,
	{
		if (*ptr  == '\n')								// if byte is newline,
			nl_c++;											// increment byte counter
		if(nl_c == 0)									// if no newlines have been found,
			ft_push_front(ptr, dest, 1);					// push byte to destination list
		else											// else if a newline has been found
		{
			if (nl_c == 1 && !*backup)						// if this is the first push to backup list,
				dest = i;										// store the bytes read into dest list
			ft_push_front(ptr, backup, 1);					// push byte to backup list
		}
		i++;											// increment byte counter
		ptr++;											// increment byte pointer to point to the next byte
	}
	if (nl_c == 0)									// if no newline was found,
		return (i);										// return the bytes read to dest list
	return (dest);									// return the bytes read to dest list
}

void	ft_lst_pushfront(void const *content, t_list **alst, size_t content_size)	// add content to front of list 
{
	if (alst != NULL && content != NULL)						// if list exists and content exists,
	{
		if(!*alst)													// if head pointer doest not exist,
			*alst = ft_lstnew(content, content_size);					// create new first node
		else														// if head pointer does exist,
			ft_lstadd(alst, ft_lstnew(content, content_size));			// add contents to front of list
	}
}

static void load_string(t_list **dest, char **line, ssize_t total)	// load the finished dest line into the string to be returned
{
	char *back;														// pointer that iterates backwards through the string
	t_list *start;													// trailing list pointer used to free a node once it has been read

	start = *dest;													// copy the starting point of the list
	if(*line)														// if there is a previous line stored,
		ft_strdel(line);												// free it, and set its pointer to NULL
	*line = ft_strnew(total - 1);									// create a new string with the required size
	total--;														// decrement total, so that the null terminator is not overridden
	back = *line+total;												// set the backpointer to the end of the string
	while(*dest)													// while there are nodes in the list,
	{
		*back = *(char*)(*dest)->content;								// read the content of the node into the string
		*dest = (*dest)->next;											// go to the next node
		free(start);													// free the current node
		start = *dest;													// set trailing pointer to the next node
		back = back - 1;												// decrement the copying pointer
	}
}
