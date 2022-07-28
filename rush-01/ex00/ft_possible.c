/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_possible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:47:39 by abruere           #+#    #+#             */
/*   Updated: 2022/07/17 19:11:43 by abruere          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	***ft_fill_possible(int ***tem, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < n)
	{
		while (j < n)
		{
			while (k < n)
			{
				tem[i][j][k] = k + 1;
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (tem); 
}

int	***ft_consider_tab_tem(int ***tem, int **tab, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < n)
	{
		while (j < n)
		{
			if (tab[i][j])
			{
				while (k < n)
				{
					if (tem[i][j][k] != tab[i][j])
						tem[i][j][k] = 0;
					k++;
				}
				k = 0;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (tem);
}

int	***ft_consider_input_tem(int ***tem, int **input, int n)
{
	int	i;
	
	i = 0;
	while (i < n)
	{
		if (input[0][i] == 2 && ft_check_tem(tem, 0, i, n) == 0)
			tem[0][i][3] = 0;
		if (input[0][i] == 3 && ft_check_tem(tem, 0, i, n) == 0)
		{
			tem[0][i][2] = 0;
			tem[0][i][3] = 0;
		}
		if (input[1][i] == 2 && ft_check_tem(tem, 3, i, n) == 0)
			tem[3][i][3] = 0;
		if (input[1][i] == 3 && ft_check_tem(tem, 3, i, n) == 0)
		{
			tem[3][i][2] = 0;
			tem[3][i][3] = 0;
		}
		if (input[2][i] == 2 && ft_check_tem(tem, i, 0, n) == 0)
			tem[i][0][3] = 0;
		if (input[2][i] == 3 && ft_check_tem(tem, i, 0, n) == 0)
		{
			tem[i][0][2] = 0;
			tem[i][0][3] = 0;
		}
		if (input[3][i] == 2 && ft_check_tem(tem, i, 3, n) ==0)
			tem[i][3][3] = 0;
		if (input[3][i] == 3 && ft_check_tem(tem, i, 3, n) == 0)
		{
			tem[i][3][2] = 0;
			tem[i][3][3] = 0;
		}
		i++;
	}
	return (tem);
}

int	***ft_possible(int **input, int **tab, int n)
{
	int	***tem;

	tem = ft_malloc3(n);
	tem = ft_fill_possible(tem, n);
	tem = ft_consider_tab_tem(tem, tab, n);
	tem = ft_consider_input_tem(tem, input, n);
	return (tem);
}

// A SUPPRIMER POUR LE RENDU
void	ft_display_po(int ***tab, int n)
{
	int	i;
	int	j;
	int	k;
	char	c;

	i = 0;
	j = 0;
	k = 0;
	c = 'c';
	write (1, "{", 1);
	while (i < n)
	{
		write (1, "{ ", 2);
		while (j < n)
		{
			write (1, "{", 1);
			while (k < n)
			{
				c = tab[i][j][k] + 48;
				write (1, &c, 1);
				if (k != 3)
					write (1, ",", 1);
				k++;
			}
			k = 0;
			write (1, "}", 1);
			if (j != 3)
				write (1, ", ", 2);
			j++;
		}
		j = 0;
		write (1, " }", 2);
		if (i != 3)
		{
			write (1, ", ", 2);
			write (1, "\n", 1);
		}
		i++;
	}
	write (1, "}", 1);
	return ;
}

//A SUPPRIMER POUR LE RENDU
int	main(void)
{
	int	n;
	int	**tab;
	int	**input;
	int	***tem;

	n = 4;
	tab = ft_malloc2(n);
	tab[0][0] = 0;
	tab[0][1] = 0;
	tab[0][2] = 1;
	tab[0][3] = 4;
	tab[1][0] = 0;
	tab[1][1] = 0;
	tab[1][2] = 2;
	tab[1][3] = 0;
	tab[2][0] = 4;
	tab[2][1] = 0;
	tab[2][2] = 3;
	tab[2][3] = 0;
	tab[3][0] = 0;
	tab[3][1] = 0;
	tab[3][2] = 4;
	tab[3][3] = 0;
	input = ft_malloc2(n);
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
	tem = ft_malloc3(n);
	tem = ft_possible(input, tab, n);
	ft_display_po(tem, n);
	return (0);
}
