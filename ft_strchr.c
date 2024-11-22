/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:16:11 by dimachad          #+#    #+#             */
/*   Updated: 2024/11/22 23:19:37 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char *ft_strchr(const char *s, int c)
{
	int		i_str;

	i_str = 0;
	while (s[i_str])
	{
		if (s[i_str] == c)
			return ((char *)&s[i_str]);
		i_str++;
	}
	return (NULL);
}
