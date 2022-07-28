/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:03:45 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/24 21:43:31 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_count_str(char **strs)
{
	int	args;

	args = 0;
	while (strs[args] != NULL)
		args++;
	return (args);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_display(char **tab, char **strs)
{
	int	i;
	int	k;
	int	count;

	count = 0;
	while (strs[count] != NULL)
		count++;
	i = -1;
	while (strs[++i] != NULL)
	{
		k = 0;
		while (tab[2 * (++k)])
		{
			if (ft_strcmp(strs[i], tab[2 * k]) == 0)
			{
				write(1, " ", 1);
				ft_putstr(tab[(2 * k) + 1]);
			}
		}
	}
}
