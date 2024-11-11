/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:56:07 by dimachad          #+#    #+#             */
/*   Updated: 2024/11/12 00:33:32 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

int	ft_isalpha(char *str);

struct TestString
{
	char	*label;
	char	*value;
};

void	test_function(char *label, char *value, int (*test_func)(char *))
{
	int	result;

	result = test_func(value);
	printf("%d -> %s\n", result, label);
}

int	main(void)
{
	struct	TestString test_strings[] =
	{
		{ "alphanumeric", "a8a7d7fg0g9g51n3m4" },
		{ "alphabetical", "asdfghkjlz" },
		{ "numerical", "1234567890"},
		{ "empty", "" },
		{ "space", " " },
		{ "null", "\n" },
	};
	int	(*test_functions[])(char *) = {ft_isalpha};
	const char *test_function_names[] = { "ft_isalpha" };
	size_t	total_strs = sizeof(test_strings) / sizeof(test_strings[0]);
	size_t	total_funcs = sizeof(test_functions) / sizeof(test_functions[0]);
	size_t	i_function;
	size_t	i_str;

	i_function = 0;
	while (i_function < total_funcs)
	{
		printf("//: %s\n", test_function_names[i_function]);
		i_str = 0;
		while (i_str < total_strs)
		{
			test_function(test_strings[i_str].label, test_strings[i_str].value, test_functions[i_function]);
			i_str++;
		}
		printf("\n");
		i_function++;
	}
	return (0);
}
