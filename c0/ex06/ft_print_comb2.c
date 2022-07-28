/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 08:04:56 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/07 11:01:51 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_conv_putchar(int q, int w)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = (q / 10) + '0';
	b = (q % 10) + '0';
	c = (w / 10) + 48;
	d = (w % 10) + 48;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (q < 98)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	q;
	int	w;

	q = 0;
	w = 1;
	while (q <= 99)
	{
		while (w <= 99)
		{
			if (q != w)
			{
				ft_conv_putchar(q, w);
			}
			w++;
		}
		q++;
		w = q;
	}
}
