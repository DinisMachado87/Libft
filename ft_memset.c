#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*memCharArr;

	memCharArr = (unsigned char*)b;
	i = 0;
	while (i <= len)
	{
		memCharArr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
