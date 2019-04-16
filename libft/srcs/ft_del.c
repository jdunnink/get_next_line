/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_del.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/14 13:57:04 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/14 15:16:44 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del(void *content, size_t content_size)
{
	if (content && content_size)
	{
		free(content);
		content_size = 0;
	}
}
