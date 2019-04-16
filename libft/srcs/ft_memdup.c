/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   temp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/14 13:11:01 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/14 15:11:02 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t len)
{
	void *dest;

	if (src)
	{
		dest = ft_memalloc(len);
		dest = ft_memcpy(dest, src, len);
		return (dest);
	}
	return (0);
}
