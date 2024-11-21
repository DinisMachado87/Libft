/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:56:07 by dimachad          #+#    #+#             */
/*   Updated: 2024/11/21 15:02:19 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size);

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

void	print_buffer(const char *buffer, size_t size)
{
	size_t	i;

	i = 0;
	while (size--)
	{
		printf("%02x ", (unsigned char)buffer[i]);
		i++;
	}
	printf("\n");
}

void	memsetTests(void *(*function)(void *, int, size_t), char *funcName, void *(*original_function)(void *, int, size_t), char *original_funcName)
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

void	bzeroTests(void (*function)(void *, size_t), char *funcName, void (*original_function)(void *, size_t), char *original_funcName)
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

void	memcpyTests(void *(*ft_function)(void *, const void *, size_t),char *ft_name, void *(*function)(void *, const void *, size_t), char *name)
{
	char	*ft_buffer = "1234564899";
	char	*buffer = "1234564899";
	void	*ft_bufferCpy[10];
	void	*bufferCpy[10];

	ft_function(ft_bufferCpy, ft_buffer, 10);
	function(bufferCpy, buffer, 10);
	printf("\n-----\n%s: ", ft_name);
	print_buffer((const char *)ft_buffer, 10);
	printf("%s: ", name);
	print_buffer((const char *)buffer, 10);
	printf("\n-----\n\n");
}

void	strcpyTests()
{
	char	dst[10];
	char	*src = "glamourous";
	printf("-----\nstrlcpy\n-----\n");
	printf("%zu - %s \n\n\n", ft_strlcpy(dst, src, 10), dst);

	char	dst2[50] = "hi, ";
	char	*src2 = "glamourous";
	printf("-----\nstrlcat\n-----\n");
	printf("%zu - %s \n\n", ft_strlcat(dst2, src2, 20), dst2);
}

int	main(void)
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
	printf("-----\nbzero tests\n-----\n-----\n\n");
	bzeroTests(ft_bzero, "ft_bzero", bzero, "bzero");
	memcpyTests(ft_memcpy, "ft_memcpy", memcpy, "memcpy");
	memcpyTests(ft_memmove, "ft_memmove", memmove, "memmove");
	strcpyTests();
	printf("-----\nbzero tests\n-----\n-----\n\n");
	printf("%c: ft_toupper // %c: toupper\n", ft_toupper('a'), toupper('a'));
	printf("%c: ft_toupper // %c: toupper\n", ft_toupper('z'), toupper('z'));
	printf("%c: ft_toupper // %c: toupper\n", ft_toupper('a' - 1), toupper('a' - 1));
	printf("%c: ft_toupper // %c: toupper\n", ft_toupper('z' + 1), toupper('z' + 1));
	return (0);
}

