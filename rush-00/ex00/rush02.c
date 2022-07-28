/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:23:25 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/09 13:25:39 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putline(char a, char b, char c, int x)
{
	int	i;

	i = -1;
	ft_putchar(a);
	x--;
	while (++i < x - 1)
		ft_putchar(b);
	if (x >= 1)
		ft_putchar(c);
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	if (x == 1 && y == 1)
	{
		ft_putchar('A');
		ft_putchar('\n');
		return ;
	}
	ft_putline('A', 'B', 'A', x);
	ft_putchar('\n');
	y--;
	i = -1;
	while (++i < y - 1)
	{
		ft_putline('B', ' ', 'B', x);
		ft_putchar('\n');
	}
	if (y >= 1)
	{
		ft_putline('C', 'B', 'C', x);
		ft_putchar('\n');
	}
}
