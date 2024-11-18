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
#include <ctype.h>
#include <libc.h>
#include <string.h>

int 	ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

struct	TestChar
{
	char	*name;
	int		c;
};

struct	TestString
{
	char	*name;
	char	*str;
};

void	charTests(int (*function)(int), char *funcName, int (*original_function)(int), char *original_funcName)
{
	int		i_t_char;

	struct	TestChar test_char[] =
	{
		{"alphabetical", 'a'},
		{"numerical", '1'},
		{"space", ' '},
		{"null", '\n'},
		{"non-ascii", 200},
		{"invisible printable under 40", 34},
	};
	i_t_char = 0;
	while (i_t_char < 6)
	{
		printf("%d: ", function(test_char[i_t_char].c));
		printf("%s ", funcName);
		printf("%s\n", test_char[i_t_char].name);
		printf("%d: ", original_function(test_char[i_t_char].c));
		printf("%s ", original_funcName);
		printf("%s\n", test_char[i_t_char].name);
		printf("-----\n");
		i_t_char++;
	}
	printf("\n\n");
}

void	strTests(size_t (*function)(const char*), char *funcName, size_t (*original_function)(const char*), char *original_funcName)
{
	int i_t_str;
	struct TestString test_string[] =
	{	
		{"alphanumeric", "a8a7d7fg0g9g51n3m4"},
		{"alphabetical", "asdfghkjlz"},
		{"numerical", "1234567890"},
		{"empty", ""},
		{"space", " "},
		{"null", "\n"},
	};

	i_t_str = 0;
	while (i_t_str < 6)
	{
		printf("%zu: ", function(test_string[i_t_str].str));
		printf("%s ", funcName);
		printf("%s\n", test_string[i_t_str].name);
		printf("%zu: ", original_function(test_string[i_t_str].str));
		printf("%s ", original_funcName);
		printf("%s\n", test_string[i_t_str].name);
		printf("-----\n");
		i_t_str++;
	}
	printf("\n\n");
}

void print_buffer(const char *buffer, size_t size)
{
	size_t	i;

	i = 0;
	while (size--)
	{
		printf("%02x ", (unsigned char)buffer[i]);
	}
	printf("\n");
}

void memsetTests(void *(*function)(void *, int, size_t), char *funcName, void *(*original_function)(void *, int, size_t), char *original_funcName)
{
	int i_t_char;
	struct TestChar test_char[] =
			{
					{"alphabetical", 'a'},
					{"numerical", '1'},
					{"space", ' '},
					{"null", '\n'},
					{"non-ascii", 200},
					{"invisible printable under 40", 34},
			};
	i_t_char = 0;
	while (i_t_char < 6)
	{
		void	*ft_buffer[10];
		void	*buffer[10];

		function(ft_buffer, test_char[i_t_char].c, 10);
		original_function(buffer, test_char[i_t_char].c, 10);
		printf("%s: ", funcName);
		print_buffer((const char *)ft_buffer, 10);
		printf("%s: ", original_funcName);
		print_buffer((const char *)buffer, 10);
		printf("-----\n");

		i_t_char++;
	}
	printf("\n");
}

void bzeroTests(void (*function)(void *, size_t), char *funcName, void (*original_function)(void *, size_t), char *original_funcName)
{
	void	*ft_buffer[10];
	void	*buffer[10];

	function(ft_buffer, 10);
	original_function(buffer, 10);
	printf("%s: ", funcName);
	print_buffer((const char *)ft_buffer, 10);
	printf("%s: ", original_funcName);
	print_buffer((const char *)buffer, 10);
	printf("\n");
}

int main(void)
{
	charTests(ft_isdigit, "ft_isdigit", isdigit, "isdigit");
	charTests(ft_isalpha, "ft_isalpha", isalpha, "isalpha");
	charTests(ft_isalnum, "ft_isalnum", isalnum, "isalnum");
	charTests(ft_isascii, "ft_isascii", isascii, "isascii");
	charTests(ft_isprint, "ft_isprint", isprint, "isprint");
	printf("-----\nstr tests\n-----\n\n");
	strTests(ft_strlen, "ft_strlen", strlen, "strlen");
	printf("-----\nbuffer tests\n-----\n\n");
	memsetTests(ft_memset, "ft_memset", memset, "memset");
	printf("-----\nbzero tests\n-----\n-----\n");
	bzeroTests(ft_bzero, "ft_bzero", bzero, "bzero");
	return (0);
}

