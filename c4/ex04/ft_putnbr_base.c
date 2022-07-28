/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:04:59 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/26 21:44:31 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		if (base[i] == '+' || base[i] == '-')
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base_inside(long int nbr, char *base)
{
	long int	long_nbr;

	long_nbr = nbr;
	if (ft_is_base(base) == 1)
	{
		if (long_nbr < 0)
		{
			ft_putchar('-');
			ft_putnbr_base_inside(long_nbr * -1, base);
		}
		else if (long_nbr < ft_strlen(base))
			ft_putchar(base[long_nbr]);
		else
		{
			ft_putnbr_base_inside(long_nbr / ft_strlen(base), base);
			ft_putnbr_base_inside(long_nbr % ft_strlen(base), base);
		}
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	long_nbr;

	long_nbr = nbr;
	ft_putnbr_base_inside(long_nbr, base);
}
