/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 18:22:18 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/03 11:06:23 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	*ptr;
	unsigned int	i;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	ptr = 0;
	while (i < n && ptr == 0)
	{
		s1[i] = s2[i];
		if (s1[i] == ((unsigned char)c))
			ptr = &s1[i] + 1;
		i++;
	}
	return ((void*)ptr);
}
