/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:25:42 by abruere           #+#    #+#             */
/*   Updated: 2022/07/17 15:29:14 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**ft_malloc2(int n)
{
	int	i;
	int	**tab;

	tab = malloc(sizeof(int *) * n);
	i = -1;
	while (++i < n)
		tab[i] = malloc(sizeof(int) * n);
	return (tab);
}

int	***ft_malloc3(int n)
{
	int	***tem;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tem = malloc(sizeof(int **) * n);
	while (i < n)
	{
		tem[i] = malloc(sizeof(int *) * n);
		while (j < n)
		{
			tem[i][j] = malloc(sizeof(int) * n);
			j++;
		}
		j = 0;
		i++;
	}
	return (tem);
}