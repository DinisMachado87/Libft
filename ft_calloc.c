/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:46:59 by dimachad          #+#    #+#             */
/*   Updated: 2024/12/03 22:19:50 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t memcount, size_t size)
{
	unsigned char	*arr;
	size_t			i_mem;

	i_mem = 0;
	arr = malloc(memcount * size);
	if (!arr)
		return (NULL);
	while (i_mem < memcount * size)
	{
		arr[i_mem] = 0;
		i_mem++;
	}
	return (arr);
}
