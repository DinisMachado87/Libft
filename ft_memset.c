/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:47:56 by dimachad          #+#    #+#             */
/*   Updated: 2024/11/18 20:47:58 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*memCharArr;

	memCharArr = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		memCharArr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
