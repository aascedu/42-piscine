/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:30:14 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/26 11:33:00 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (0 <= nbr && nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_power(nb, (power - 1)));
}

int	ft_is_comb(int nb, int n)
{
	int	i;
	int	x;
	int	y;
	int	power;

	i = -1;
	while (++i < n - 1)
	{
		power = ft_power(10, n - i);
		x = nb % power / (power / 10);
		y = nb % (power / 10) / (power / 100);
		if (!(x < y))
			return (0);
	}
	return (1);
}

void	ft_print_combn(int n)
{
	int	i;
	int	power;

	power = ft_power(10, n - 1);
	i = ft_power(10, n - 2) - 1;
	if (n > 9)
		return ;
	else if (n == 9)
	{
		write(1, "012345678, 012345679, 012345689, 012345789, 012346789, ", 55);
		write(1, "012356789, 012456789, 013456789, 023456789, 123456789", 53);
		return ;
	}
	while (++i < (11 - n) * power)
	{	
		if (ft_is_comb(i, n) == 1)
		{
			if (i < power && n > 1)
				write(1, "0", 1);
			ft_putnbr(i);
			if ((i / power) != (10 - n))
				write(1, ", ", 2);
		}
	}
}
