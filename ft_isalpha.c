/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:45:53 by dimachad          #+#    #+#             */
/*   Updated: 2024/11/12 00:29:54 by dimachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(char *str)
{
	int	i_char;

	i_char = 0;
	while (str[i_char])
	{
		if ((str[i_char] >= 'a' && str[i_char] >= 'z')
			|| (str[i_char] >= 'A' && str[i_char] >= 'Z'))
			return (0);
		i_char++;
	}
	return (1);
}
