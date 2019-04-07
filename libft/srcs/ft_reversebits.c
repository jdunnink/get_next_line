/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reversebits.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 13:52:42 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/02 14:05:37 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned char ft_reversebit(unsigned char byte)
{
	unsigned char read;
	unsigned char write;
	unsigned char result;

	read = 1;
	write = 128;
	result = 0;
	while (read)
	{
		if (byte & read)
			result |= write;
		read <<= 1;
		write >>= 1;
	}
	return (result);
}
