/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 16:29:37 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/03/27 12:58:30 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	trim_left(char const *s)
{
	int i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (s[i] != '\0'))
		i++;
	return (i);
}

static	int	trim_right(char const *s)
{
	size_t	len;
	int		i;

	len = ft_strlen(s);
	if (len == 0)
		return (0);
	i = len - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*dest;
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	start = trim_left(s);
	if (start == ft_strlen(s))
		return (ft_strnew(0));
	end = trim_right(s);
	dest = ft_strsub(s, start, (end - start) + 1);
	return (dest);
}
