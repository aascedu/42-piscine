/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:53:45 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/28 11:33:38 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
			|| base[i] == '\f' || base[i] == '\n'
			|| base[i] == '\t' || base[i] == '\v' || base[i] == '\r')
			return (0);
	}
	i = -1;
	while (base[++i])
	{
		k = i;
		while (base[++k])
		{
			if (base [i] == base[k])
				return (0);
		}
	}
	return (1);
}

int	ft_place_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_char_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == '\r')
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	result = 0;
	while (ft_char_in_base(str[i], base) == 1)
	{
		result = (result * ft_strlen(base)) + ft_place_in_base(base, str[i]);
		i++;
	}
	return (result * sign);
}
