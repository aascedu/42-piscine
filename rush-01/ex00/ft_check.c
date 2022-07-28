/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 19:36:50 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/17 19:36:59 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_check_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && (str[i] >= 49 && str[i] <= 52))
			i++;
		else if (i % 2 == 1 && str[i] == ' ' && str[i + 1] != '\0')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_tem(int ***tab, int a, int b, int n)
{
	int	c;
	int	check;
	int	i;

	c = 0;
	check = 0;
	i = 0;
	while (i < n)
	{
		if (tab[a][b][i] != 0)
			c++;
		i++;
	}
	if (c == 1)
		check = 1;
	return (check);
}
