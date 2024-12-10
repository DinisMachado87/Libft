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

static size_t	count_words(const char *str, char splitter)
{
	size_t	num_words;
	char	prev_char;

	num_words = 0;
	prev_char = splitter;
	while (*str)
	{
		if (prev_char == splitter && *str != prev_char)
			num_words++;
		prev_char = *str;
		str++;
	}
	return (num_words);
}

static char		*extract_word(const char *str, char splitter)
{
	char	*word;
	size_t	word_len;
	size_t	i_word;

	word_len = 0;
	while (str[word_len] && str[word_len] != splitter)
		word_len++;
	word = (char *)malloc((word_len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i_word = 0;
	while (i_word < word_len)
	{
		word[i_word] = str[i_word];
		i_word++;
	}
	word[i_word] = '\0';
	return (word);
}

static void free_word_arr(char **word_arr, size_t i_arr)
{
	while (i_arr > 0)
	{
		free(word_arr[i_arr - 1]);
		i_arr--;
	}
	free(word_arr);
}

char	**ft_split(const char *str, char splitter)
{
	char	**word_arr;
	size_t	arr_size;
	size_t	i_arr;

	if (!str)
		return (NULL);
	arr_size = count_words(str, splitter);
	word_arr = (char **)malloc((arr_size + 1) * sizeof(char *));
	if (!word_arr)
		return (NULL);
	i_arr = 0;
	while (*str && i_arr < arr_size)
	{
		while (*str && *str == splitter)
			str++;
		if (*str)
		{
			word_arr[i_arr] = extract_word(str, splitter);
			if (!word_arr[i_arr])
			{
				free_word_arr(word_arr, i_arr);
				return (NULL);
			}
		}
		i_arr++;
		while (*str && *str != splitter)
			str++;
	}
	word_arr[i_arr] = NULL;
	return (word_arr);
}

/*
#include <stdio.h>

int		main()
{
	printf("count_words: %zu\n", count_words("sddjlkksdflsdkdjlsd", 'k'));
	printf("extract_word: %s\n", extract_word("sddjlkksdflsdkdjlsd", 'k'));
	return (0);
}
*/