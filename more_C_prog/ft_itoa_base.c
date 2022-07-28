/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:46:48 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/22 15:46:59 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_size(int number, char *base, int sign)
{
	int	i;

	i = 0;
	while (number >= ft_strlen(base))
	{
		number /= ft_strlen(base);
		i++;
	}
	if (sign == -1)
		i++;
	return (++i);
}

char	*ft_rev_str(char *str)
{
	int		i;
	int		size;
	char	temp;

	size = ft_strlen(str);
	i = -1;
	while (++i < (size / 2))
	{
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
	}
	return (str);
}

int	ft_is_base(char *base)
{
	int	i;
	int	k;

	if (ft_strlen(base) <= 1)
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| base[i] == '\f' || base[i] == '\n' || base[i] == '\t'
			|| base[i] == '\v' || base[i] == '\r')
			return (0);
	}
	i = -1;
	while (base[++i])
	{
		k = i;
		while (base[++k])
		{
			if (base[i] == base[k])
				return (0);
		}
	}
	return (1);
}

char	*ft_itoa_base(int number, char *base)
{
	char	*result;
	int		sign;
	int		i;

	if (ft_is_base(base) == 0)
		return (0);
	sign = 1;
	if (number < 0)
	{
		sign = -1;
		number = number * -1;
	}
	result = malloc(sizeof(char) * (ft_size(number, base, sign) + 1));
	i = 0;
	while (number >= ft_strlen(base))
	{
		result[i++] = base[number % ft_strlen(base)];
		number = number / ft_strlen(base);
	}
	result[i] = base[number];
	if (sign == -1)
		result[++i] = '-';
	result[++i] = '\0';
	return (ft_rev_str(result));
}
