/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienW <julienW@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:35:30 by cw3l              #+#    #+#             */
/*   Updated: 2026/03/01 21:08:02 by julienW          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_recursive_power(int nb, int power)
{
    if (power == 0)
        return (1);
    if (nb == 0)
        return (0);
    return (nb * ft_recursive_power(nb, power - 1));
}

void ft_recursive_power_assertion(void)
{
	assert(ft_recursive_power(0,0) == 1);
	assert(ft_recursive_power(10,0) == 1);
	assert(ft_recursive_power(0,10) == 0);
	assert(ft_recursive_power(10,3) == 1000);
	assert(ft_recursive_power(10,3) == 1000);
	assert(ft_recursive_power(2,3) == 8);
	assert(ft_recursive_power(5,5) == 3125);
	assert(ft_recursive_power(1,5) == 1);
}