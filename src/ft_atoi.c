/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:31:01 by vcordeir          #+#    #+#             */
/*   Updated: 2021/12/05 18:31:10 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(int c)
{
	if ((c >= 7 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static	int	calculate_nb(const char *str, int mult)
{
	int	res;

	res = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (mult * res);
}

int	ft_atoi(const char *str)
{
	int	mult;
	int	bool_first;

	mult = 1;
	bool_first = 1;
	while (*str != '\0')
	{
		if (*str == '-' && bool_first)
		{
			mult = -1;
			bool_first = 0;
		}
		else if (*str == '+' && bool_first)
			bool_first = 0;
		else if (ft_isdigit(*str))
			return (calculate_nb(str, mult));
		else if (!(ft_isspace(*str) && bool_first))
			return (0);
		str++;
	}
	return (0);
}
