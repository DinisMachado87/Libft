/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:23:05 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/05 02:59:13 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*extract_word(char *str, char splitter)
{
	char	*word;
	size_t	word_len;
	size_t	i_word;

	word_len  = 0;
	while (str[word_len] && str[word_len] != splitter)
		word_len++;
	word = (char *)malloc(word_len * sizeof(char));
	if (!word)
		return (NULL);
	i_word = 0;
	while (i_word <= word_len)
	{
		word[i_word] = str[i_word];
		i_word++;
	}
	return (word);
}


static size_t	count_splitters(char *s, char splitter)
{
	size_t	i_str;
	size_t	num_words;

	i_str = 0;
	num_words = 1;
	while (s[i_str])
	{
		if (s[i_str] == splitter)
			num_words++;
		i_str++;
	}
	return (num_words);
}

char	**ft_split(char const *s, char splitter)
{
	char	**word_arr;
	size_t	arr_size;
	size_t	i_arr;
	char	*remaining_str;

	remaining_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));	
	ft_strlcpy(remaining_str, s, ft_strlen(s));
	arr_size = 1 + count_splitters(remaining_str, splitter);
	word_arr = (char **)malloc(arr_size * sizeof(char *));
	if (!word_arr)
		return (NULL);
	i_arr = 0;
	while (i_arr < arr_size - 1)
	{
		extract_left(&remaining_str, word_arr, i_arr, splitter);
		i_arr++;
	}
	word_arr[arr_size - 1] = NULL;
	return(word_arr);
}
/*
#include <stdio.h>

int		main()
{
	ft_split("sddjlksdflsdkdjlsd", 'k');
	return (0);
}
*/
