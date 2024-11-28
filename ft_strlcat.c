/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:36:56 by dimachad          #+#    #+#             */
/*   Updated: 2024/11/28 20:56:20 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i_dst;
	size_t	i_src;
	size_t	src_len;

	i_dst = 0;
	i_src = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	while (dst[i_dst])
		i_dst++;
	while (src[i_src] && i_src + i_dst < size - 1)
	{
		dst[i_src + i_dst] = src[i_src];
		i_src++;
	}
	dst[i_src + i_dst] = '\0';
	return (src_len + i_dst);
}
