/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 11:02:19 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/17 19:34:52 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**ft_create_input(int *tab, int n)
{
	int	i;
	int	row;
	int	column;
	int	**input;

	input = ft_malloc2(n);
	row = 0;
	i = 0;
	while (row < n)
	{
		column = 0;
		while (column < n)
		{
			input[row][column] = tab[i];
			column++;
			i++;
		}
		row++;
	}
	return (input);
}

int	**ft_my_atoi(char *str, int n)
{
	int	i;
	int	k;
	int	*tab;
	int	**input;

	tab = malloc(sizeof(int) * (n * n));
	i = 0;
	k = 0;
	while (str[i])
	{
		if (i % 2 == 0)
		{
			tab[k] = str[i] - 48;
			k++;
		}
		i++;
	}
	input = ft_create_input(tab, n);
	return (input);
}
