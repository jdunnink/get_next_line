/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 11:39:21 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/03/22 15:04:33 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char *t;

	t = s;
	while (*s != '\0')
		s++;
	while (*s != *t)
	{
		if (*s == c)
			return ((char*)s);
		s--;
	}
	if (*s == c)
		return ((char*)s);
	return (0);
}
