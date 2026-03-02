/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdric.b <cdric.b@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:18:47 by cbouhadr          #+#    #+#             */
/*   Updated: 2026/03/02 10:19:40 by cdric.b          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int check_base(const char *base)
{
	int i;
	int j;

	if (!base || !(*base))
		return (0);
	i = 0;
	if(base[i] == 43 || base[i] == 45 || ft_isspace(base[i]))
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if(base[j] == 43 || base[j] == 45 || ft_isspace(base[j]) || base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

static size_t original_value_len(const char *str, const char *base)
{
	size_t counter;

	counter = 0;
	while(*str && ft_isspace(*str))
		str++;
	while (*str && (*str == 45 || *str == 43))
		str++;
	while (ft_isset(*str, base))
	{
		str++;
		counter++;
	}
	return (counter);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int result;
	int is_neg;
	size_t value_len;

	result = 0;
	is_neg = 0;
	if (!str || !check_base(base))
		return (result);
	value_len = original_value_len(str, base) - 1;
	while (*str && ft_isspace(*str))
		str++;
	while (*str && (*str == 45 || *str == 43))
	{
		if (*str == 45)
			is_neg++;
		str++;
	}
	while (*str && ft_isset(*str, base))
	{
		result = result + (ft_index_of_char(base,*str) * (ft_recursive_power(ft_strlen(base), value_len--)));
		str++;	
	}
	if(is_neg % 2 != 0)
		return(result * -1);
	return (result);
}


void ft_atoi_base_assertion(void)
{
	int r;
	
	printf("\e[0;33m""STARTING ASSERTION FOR ATOI_BASE\n" "\e[0;0m");
	assert(!ft_atoi_base("101010", ""));
    assert(!ft_atoi_base("101010", NULL));
    assert(!ft_atoi_base(NULL, NULL));
    assert(!ft_atoi_base("101010", "-0123456789"));
    assert(!ft_atoi_base("101010", "+0123456789"));
    assert(!ft_atoi_base("101010", "\n0123456789"));
    assert(!ft_atoi_base("101010", "012345-6789"));
    assert(!ft_atoi_base("101010", "012345+6789"));
    assert(!ft_atoi_base("101010", "012345\n6789"));
    assert(!ft_atoi_base("101010", "0123456789-"));
    assert(!ft_atoi_base("101010", "0123456789+"));
    assert(!ft_atoi_base("101010", "0123456789\n"));
    assert(!ft_atoi_base("101010", "00123456789"));
    assert(!ft_atoi_base("101010", "01234556789"));
    assert(!ft_atoi_base("101010", "01234567898"));
    assert(!ft_atoi_base("101010", "0"));

    assert(ft_atoi_base("101010", "01") == 42);


	assert(original_value_len("    +--+-+-01234ABF9xxxxx", "0123456789ABCDEF") == 9);
	assert(original_value_len("    +--+-+-01101101001110001xxxxx", "0123456789ABCDEF") == 17);

	r = ft_atoi_base("2a", "0123456789abcdef");
    assert(r == 42);
    r = ft_atoi_base("     +++---2alllllxxxx", "0123456789abcdef");
    assert(r == -42);
    r = ft_atoi_base("     +++101010lllllxxxx", "01");
    assert(r == 42);
    r = ft_atoi_base("     +++01234lllllxxxx", "0123456789ABCDEF");
    assert(r == 4660);
    r = ft_atoi_base("     +++-----+++12345lllllxxxx", "01234567");
    assert(r == -5349);

	printf("\e[0;32m""ASSERTION FOR ATOI BASE: OK\n""\e[0;0m");
}