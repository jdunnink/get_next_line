/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 17:47:52 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/04 15:13:20 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	int r;
	char *nl;
	int i;

	if(argc != 2)
	{
		ft_putendl("You have given no/too many files to read");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);

	i = 2;
	while(i-- > 0)
	{ 
		r = get_next_line(fd, &nl);
		printf("%s\n", nl);
	}
	close(fd);
	return (0); 
}
