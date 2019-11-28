/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 11:43:59 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/03 11:04:48 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	long	int	ft_labs(long int nb)
{
	if (nb < 0)
		return (nb * -1);
	else
		return (nb);
}

static	long	int	ft_find_size(long int value, int base)
{
	int i;
	int neg;

	i = 0;
	neg = 0;
	if (value < 0 && base == 10)
		neg = 1;
	value = ft_labs(value);
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i + neg);
}

char				*ft_itoa_base(int value, int base)
{
	int			len;
	long int	temp;
	char		*dest;
	char		*tab;

	temp = (long int)value;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	len = ft_find_size(temp, base);
	temp = ft_labs(temp);
	dest = ft_strnew(len);
	while (len)
	{
		len--;
		dest[len] = tab[(temp % base)];
		temp /= base;
	}
	if (value < 0 && base == 10)
		dest[0] = '-';
	return (dest);
}
