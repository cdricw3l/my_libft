/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_of.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienW <julienW@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:14:07 by cbouhadr          #+#    #+#             */
/*   Updated: 2026/03/02 06:27:19 by julienW          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>

int	ft_index_of_int(int *arr, int len, int n)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == n)
			return (i);
		i++;
	}
	return (-1);
}
