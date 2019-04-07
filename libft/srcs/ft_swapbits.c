/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swapbits.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdunnink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 11:41:19 by jdunnink      #+#    #+#                 */
/*   Updated: 2019/04/02 14:12:16 by jdunnink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned char	ft_swapbits(unsigned char octet)
{
	return ((octet >> 4) + (octet >> 4));
}
