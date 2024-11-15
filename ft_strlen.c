#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i_ltr;

	i_ltr = 0;
	while (str[i_ltr])
		i_ltr++;
	return (i_ltr); 
}

