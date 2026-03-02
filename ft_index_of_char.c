/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_of_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julienW <julienW@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:14:07 by cbouhadr          #+#    #+#             */
/*   Updated: 2026/03/02 06:34:38 by julienW          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>

int	ft_index_of_char(char const *str, char c)
{
	int	i;

	if(!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void ft_index_of_char_assertion(void)
{
	printf("STARTING ASSERTION FOR INDEX_OF_CHAR\n");
	assert(ft_index_of_char("hello_berlin", 'n') == 11);
	assert(ft_index_of_char("hello_berlin", '_') == 5);
	assert(ft_index_of_char("hello_berlin", 'h') == 0);
	assert(ft_index_of_char("hello_berlin", 'p') == -1);
	assert(ft_index_of_char("", 'h') == -1);
	assert(ft_index_of_char(NULL, 'h') == -1);
	printf("ASSERTION FOR INDEX_OF_CHAR: OK\n");
}
