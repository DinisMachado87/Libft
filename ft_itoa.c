#include <strings.h>

static size_t n_len(int n)
{
	size_t	n_len;

	n_len = 0;
	if (n < 0)
	{
		n_len++;
		n = -n;
	}
	if (n == 0)
		n_len++;
	while (n != 0)
	{
		n_len++;
		n /= 10;
	}
	return (n_len);
}
/*
char	*ft_itoa(int n)
{
	
}
*/

#include <stdio.h>

int	main()
{
	printf("%zu\n", n_len(0));
	printf("%zu\n", n_len(-223412));
	printf("%zu\n", n_len(983744652));
	return (0);
}
