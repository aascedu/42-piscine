/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:22:10 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/17 19:40:22 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_which_numb_col(int i, int **tab)
{
	int	row;
	int	result;

	row = -1;
	result = 10;
	while (++row < 4)
		result = result - tab[row][i];
	return (result);
}

int	ft_which_numb_row(int i, int **tab)
{
	int	column;
	int	result;

	column = -1;
	result = 10;
	while (++column < 4)
		result = result - tab[i][column];
	return (result);
}

int	ft_check_empty(int row, int column, int **tab)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tab[i][column] != 0)
				i++;
		else
			return (0);
	}
	if (i == 3)
		tab[i][column] = ft_which_numb_col(column, tab);
	i = 0;
	while (i < 4)
	{
		if (tab[row][i] != 0)
			i++;
		else
			return (0);
	}
	if (i == 3)
		tab[row][i] = ft_which_numb_row(row, tab);
	return (tab[row][column]);
}

int	**ft_fill(int **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == 0)
				tab[i][j] = ft_check_empty(i, j, tab);
			j++;
		}
		i++;
	}		
	return (tab);
}
