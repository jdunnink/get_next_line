/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 15:52:06 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/03/27 11:14:56 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *hstack, const char *needle)
{
	int x;
	int y;

	if (needle[0] == '\0')
		return ((char*)hstack);
	x = 0;
	while (hstack[x] != '\0')
	{
		y = 0;
		while (hstack[x + y] == needle[y])
		{
			if (needle[y + 1] == '\0')
				return ((char*)hstack + x);
			y++;
		}
		x++;
	}
	return (0);
}
