/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:29:20 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/28 11:43:16 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_is_base(char *base);
int	ft_atoi_base(char *str, char *base);
int	ft_char_in_base(char c, char *base);
int	ft_place_in_base(char *base, char c);

char	*ft_rev_result(char *result)
{
	int		i;
	int		size;
	char	*rev_result;
	char	temp;

	size = ft_strlen(result);
	rev_result = malloc(sizeof(char) * (size + 1));
	if (!rev_result)
		return (NULL);
	rev_result = result;
	i = 0;
	while (i < (size / 2))
	{
		temp = result[i];
		result[i] = result[size - i - 1];
		result[size - i - 1] = temp;
		i++;
	}
	return (result);
}

int	ft_size(int number, char *str)
{
	int	i;

	i = 0;
	while (number >= ft_strlen(str))
	{
		number = number / ft_strlen(str);
		i++;
	}
	return (++i);
}

char	*ft_malloc(int number, int sign, char *base_to)
{
	char	*result;
	int		i;

	i = 0;
	if (sign == -1)
	{
		result = malloc(sizeof(char) * ft_size(number, base_to) + 2);
		if (!result)
			return (NULL);
	}
	else
	{
		result = malloc(sizeof(char) * ft_size(number, base_to) + 1);
		if (!result)
			return (NULL);
	}
	return (result);
}

char	*ft_itoa_base(int number, char *base_to, char *result, int sign)
{
	int	i;

	i = 0;
	while (number >= ft_strlen(base_to))
	{
		result[i++] = base_to[number % ft_strlen(base_to)];
		number = number / ft_strlen(base_to);
	}
	result[i++] = base_to[number];
	if (sign == -1)
	{
		sign = 0;
		result[i++] = '-';
	}
	result[i] = '\0';
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		number;
	int		sign;

	if (ft_is_base(base_from) != 1 || ft_is_base(base_to) != 1)
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	sign = 1;
	if (number < 0)
	{
		sign = -1;
		number = number * -1;
	}
	result = ft_malloc(number, sign, base_to);
	result = ft_itoa_base(number, base_to, result, sign);
	result = ft_rev_result(result);
	return (result);
}
