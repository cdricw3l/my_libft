/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:53:08 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/10/07 12:12:45 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(int n, int fd, char const *base)
{
	long	nb;
	char	digit;
	size_t	base_len;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	base_len = ft_strlen(base);
	if ((size_t)nb >= base_len)
		ft_putnbr_base_fd(nb / base_len, fd, base);
	digit = base[nb % base_len];
	write (fd, &digit, 1);
}
