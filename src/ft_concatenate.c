/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concatenate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:31:53 by vcordeir          #+#    #+#             */
/*   Updated: 2021/12/05 18:31:54 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	*ft_concatenate(char const *str, char c)
{
	int		i;
	int		len_str;
	char	*str_concat;

	if (!str)
		str_concat = (char *)malloc(2 * sizeof(char));
	else
	{
		len_str = ft_strlen(str);
		str_concat = (char *)malloc((len_str + 2) * sizeof(char));
	}
	i = 0;
	if (str != NULL)
	{
		while (i < len_str)
		{
			str_concat[i] = str[i];
			i++;
		}
		free((void *)str);
		str = NULL;
	}
	str_concat[i] = c;
	str_concat[i + 1] = '\0';
	return (str_concat);
}
