/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:31:27 by vcordeir          #+#    #+#             */
/*   Updated: 2021/12/05 18:31:32 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	ft_strrev(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
		i++;
	}
}

static int	ft_isnegative(int num)
{
	if (num < 0)
		return (1);
	else
		return (0);
}

static	void	negative_nbr(int *num, int *negative)
{
	*num *= -1;
	*negative = 1;
}

char	*ft_itoa(int num)
{
	int		i;
	int		negative;
	char	*str;

	negative = 0;
	if (num == 0)
		return (str = ft_strdup("0\0"));
	else if (num == -2147483648)
		return (str = ft_strdup("-2147483648\0"));
	i = 0;
	str = (char *)malloc(12 * sizeof(char));
	if (ft_isnegative(num))
		negative_nbr(&num, &negative);
	while (num != 0)
	{
		str[i++] = num % 10 + '0';
		num = num / 10;
	}
	if (negative)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
