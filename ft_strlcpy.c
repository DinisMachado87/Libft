/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:54:17 by dimachad          #+#    #+#             */
/*   Updated: 2024/11/28 20:40:51 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	h_strlen(const char *str)
{
	size_t	i_len;

	i_len = 0;
	while (str[i_len])
		i_len++;
	return (i_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i_ltr;
	size_t	len;

	len = h_strlen(src);
	i_ltr = 0;
	if (size > 0)
	{
		while (src[i_ltr] && i_ltr < size - 1)
		{
			dst[i_ltr] = src[i_ltr];
			i_ltr++;
		}
		dst[i_ltr] = '\0';
	}
	return (len);
}
