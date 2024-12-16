/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:43:20 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 14:24:57 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(long n)
{
	size_t	n_len;

	n_len = 0;
	if (n <= 0)
	{
		n_len++;
		n = -n;
	}
	while (n != 0)
	{
		n_len++;
		n /= 10;
	}
	return (n_len);
}

static void	rec_itoa(long num, size_t n_len, char *str_result)
{
	if (num < 0)
	{
		str_result[0] = '-';
		rec_itoa(-num, (n_len - 1), str_result + 1);
	}
	else if (num >= 10)
	{
		rec_itoa(num / 10, (n_len - 1), str_result);
		str_result[n_len] = (num % 10) + '0';
	}
	else
	{
		str_result[n_len] = num + '0';
		return ;
	}
}

char	*ft_itoa(int n)
{
	size_t	n_len;
	char	*str_result;

	n_len = num_len((long)n);
	str_result = (char *)malloc((n_len + 1) * sizeof(char));
	if (!str_result)
		return (NULL);
	str_result[n_len] = '\0';
	rec_itoa((long)n, n_len - 1, str_result);
	return (str_result);
}

/*
#include <stdio.h>

int	main()
{
	printf("n_len\n");
	printf("%zu\n", num_len(0));
	printf("%zu\n", num_len(-223412));
	printf("%zu\n", num_len(983744652));
	printf("ft_itoa\n");
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-223412));
	printf("%s\n", ft_itoa(983744652));
	return (0);
}
*/
