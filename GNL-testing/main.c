/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   benchmain.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: aholster <aholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/06 18:09:23 by aholster       #+#    #+#                */
/*   Updated: 2019/04/16 13:41:26 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		status;
	int		i;

	i = 0;
	status = 1;
	if (argc == 2)
	{
		fd = open(argv[1], 0);
		if (fd == -1)
		{
			ft_putendl("could not open file");
			return (-1);
		}
		printf("begining reading ==============\n");
		while (status != -1 && status != 0)
		{
			status = get_next_line(fd, &line);
			printf("iteration |%i| return |%d|line is|%s|\n", i,  status, line);
			i++;
			free(line);
			line = NULL;
		}
	}
	return (1);
}
