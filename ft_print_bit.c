/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:46:27 by cw3l              #+#    #+#             */
/*   Updated: 2026/03/02 11:04:37 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bit(int n, unsigned int bit)
{
	unsigned char	c;
	int b;
	int padding;
	
	b = bit - 1;
	padding = 0;
	while (b >= 0)
	{
		if (!(padding % 4) && padding != 0)
			write(1, " ", 1);
		c = ((n >> b) & 1) + '0';
		write(1, &c, 1);
		b--;
		padding++;
	}
	write(1, "\n", 1);
}
