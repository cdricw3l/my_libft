/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouhadr <cbouhadr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:53:35 by cbouhadr          #+#    #+#             */
/*   Updated: 2024/10/12 17:15:22 by cbouhadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_clean_split(char **split)
{
    char **ptr;

    ptr = split;
    while (*ptr)
    {
        free(*ptr);
        *ptr = NULL;
        ptr++;
    }
    free(split);
    split = NULL;
    return (NULL);
}

t_bool is_on_set(char c, char *charset)
{
    int i;

    if (!charset)
        return (0);
    i = 0;
    while (charset[i])
    {
        if (c == charset[i])
            return(TRUE);
        i++;
    }
    return (FALSE);
}

int count_word(char *str, char *charset)
{
    int counter;

    if(!charset && str)
        return (1);
    if(!charset && !str)
        return (0);
    counter = 0;
    while (*str)
    {
        while (*str && is_on_set(*str, charset))
            str++;
        if (*str && !is_on_set(*str, charset))
            counter++;
        while (*str && !is_on_set(*str, charset))
            str++;        
    }
    return (counter);
}


char *ft_extract_word(char **str, char *charset)
{
    char *ptr;
    char *new_str;
    int i;

    i = 0;
    ptr = *str;
    while (ptr[i] && !is_on_set(ptr[i], charset))
        i++;
    new_str  = malloc(sizeof(char) * (i + 1));
    if (!new_str)
        return (NULL);
    ptr = new_str;
    while (*(*str) && !is_on_set(*(*str), charset))
    {
        *ptr = *(*str);
        (*str)++;
        ptr++;
    }
    *ptr = '\0';
    return(new_str);
}

char **ft_split(char *str, char *charset)
{
    int     nb_word;
    char    **split;
    int i;

    if (!str)
        return (NULL);
    nb_word = count_word(str, charset);
    split = malloc(sizeof(char *) * (nb_word + 1));
    if (!split)
        return (NULL);
    i = 0;
    while (i < nb_word)
    {
        while (*str && is_on_set(*str, charset))
            str++;
        if (*str && !is_on_set(*str, charset))
        {
            split[i] = ft_extract_word(&str, charset);
            if (!split[i])
                return (ft_clean_split(split));
        }
        i++;
    }
    split[i] = NULL;
    return(split);
}
