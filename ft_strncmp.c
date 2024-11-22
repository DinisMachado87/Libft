/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:33:21 by dimachad          #+#    #+#             */
/*   Updated: 2024/11/23 00:30:41 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	fn_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char	i_str;

    i_str = 0;
    while (s1[i_str] && s2[i_str] && i_str < n)
    {
        if (s1[i_str] != s2[i_str])
            return (s1[i_str] - s2[i_str]);
        i_str++;
    }
    return (0);
}
