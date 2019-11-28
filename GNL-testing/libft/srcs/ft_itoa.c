/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 17:11:34 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/03 11:04:32 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_negative(int *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (-1);
	}
	else
		return (0);
}

static size_t	find_length(int value, int neg)
{
	size_t len;

	len = 2;
	while (value /= 10)
		len++;
	if (neg == -1)
		return (len + 1);
	else
		return (len);
}

char			*ft_itoa(int n)
{
	char			*dest;
	int				neg;
	int				temp;
	size_t			len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	temp = n;
	neg = is_negative(&n);
	len = find_length(n, neg);
	dest = (char*)malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	len--;
	dest[len] = '\0';
	while (len > 0)
	{
		len--;
		dest[len] = 48 + (n % 10);
		n = n / 10;
	}
	if (neg == -1)
		dest[0] = '-';
	return (dest);
}
