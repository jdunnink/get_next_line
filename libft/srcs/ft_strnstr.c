/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 17:30:16 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/03/28 17:23:47 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstack, const char *needle, size_t len)
{
	size_t x;
	size_t y;

	if (needle[0] == '\0')
		return ((char*)hstack);
	x = 0;
	while (hstack[x] != '\0' && x < len)
	{
		y = 0;
		while (hstack[x + y] == needle[y] && x + y < len)
		{
			if (needle[y + 1] == '\0')
				return ((char*)hstack + x);
			y++;
		}
		x++;
	}
	return (0);
}
