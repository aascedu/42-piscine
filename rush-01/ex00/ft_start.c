/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimoes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 09:48:59 by asimoes-          #+#    #+#             */
/*   Updated: 2022/07/17 19:49:04 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int	**ft_condition_line_up(int ind, int nb, int **tab, int j)
{
	int i;

	i = 0;
	while (ind == 4 && i < 4)
	{
		tab[i][j] = i + 1;
		i++;
	}
	if (ind == 1)
	{
		nb = 4;
		tab[0][j] = 4;
	}
	return (tab);
}

int	**ft_condition_line_down(int ind, int nb, int **tab, int j)
{
	int i;

	i = 0;
	while (ind == 4 && i < 4)
	{
		tab[i][j] = i + 1;
		i++;
	}
	if (ind == 1)
	{
		nb = 4;
		tab[3][j] = 4;
	}
	return (tab);
}

int	**ft_condition_col_left(int ind, int nb, int **tab, int j)
{
	int i;

	i = 0;
	while (ind == 4 && i < 4)
	{
		tab[j][i] = i + 1;
		i++;
	}
	if (ind == 1)
	{
		nb = 4;
		tab[j][0] = nb;
	}
	return(tab);
}

int	**ft_condition_col_right(int ind, int nb, int **tab, int j)
{
	int i;

	i = 0;
	while (ind == 4 && i < 4)
	{
		tab[j][i] = i + 1;
		i++;
	}
	if (ind == 1)
	{
		nb = 4;
		tab[j][3] = nb;
	}
	return (tab);
}

/*
void	ft_nb_value(int **tab)
{

}
*/

int	**ft_start(int **input)
{
	int	j;
	int **tab;

	tab = ft_malloc2(4);
	j = 0;
	while(j < 4)
	{
		ft_condition_line_up(input[0][j], tab[0][j], tab, j);
		ft_condition_line_down(input[1][j], tab[3][j], tab, j);
		ft_condition_col_left(input[2][j], tab[j][0], tab, j);
		ft_condition_col_right(input[3][j], tab[j][3], tab, j);
		j++;
	}
	return (tab);
}

int	main(void)
{
	int **input;
	int **tab;

	tab = ft_malloc2(4);
	input = ft_malloc2(4);
	input[0][0] = 3;
	input[0][1] = 2;
	input[0][2] = 4;
	input[0][3] = 1;

	input[1][0] = 2;
	input[1][1] = 2;
	input[1][2] = 1;
	input[1][3] = 2;

	input[2][0] = 3;
	input[2][1] = 2;
	input[2][2] = 1;
	input[2][3] = 3;

	input[3][0] = 1;
	input[3][1] = 3;
	input[3][2] = 3;
	input[3][3] = 2;
	tab = ft_start(input);
	ft_display(tab, 4);

	return (0);
}
