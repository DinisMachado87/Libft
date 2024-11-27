#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i_mem;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i_mem = 0;
	while (i_mem < n)
	{
		if (str1[i_mem] != str2[i_mem])
			return (str1[i_mem] - str2[i_mem]);
		i_mem++;
	}
	return (0);
}
