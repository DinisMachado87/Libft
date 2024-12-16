/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:30:40 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/16 14:28:35 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_dig(int n, int fd)
{
	char	chr;

	chr = n + '0';
	write(fd, &chr, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n <= 9)
		print_dig(n, fd);
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		print_dig(n % 10, fd);
	}
}

/*
int		main()
{
	printf("ft_putnr_fd");
	printf("\n");
	ft_putnbr_fd(9, 1);
	printf("\n");
	ft_putnbr_fd(-9, 1);
	printf("\n");
	ft_putnbr_fd(0, 1);
	printf("\n");
	ft_putnbr_fd(-0, 1);
	printf("\n");
	ft_putnbr_fd(2147483647, 1);
	printf("\n");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");
}
*/
