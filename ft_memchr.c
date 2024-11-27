#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i_mem;
	unsigned char	*str;

	str = (unsigned char *)s;
	i_mem = 0;
	while(i_mem < n)
	{
		if (str[i_mem] == (unsigned char)c)
			return ((void *)&str[i_mem]);
		i_mem++;
	}
	return (NULL);
}
