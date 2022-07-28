/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 13:32:56 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/28 10:23:39 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	copy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (src[++i])
		copy[i] = src[i];
	copy[++i] = '\0';
	return (copy);
}

void	ft_free(char **tab)
{
	int	count;
	int	i;

	count = 0;
	while (tab[count])
		count++;
	i = count + 1;
	while (--i != 0)
		free(tab[i]);
	free(tab);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	i = -1;
	tab = malloc(sizeof(char *) * (ac + 1));
	if (!tab)
		return (NULL);
	while (++i <= ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		if (!tab[i].str)
		{
			ft_free(tab);
			return (NULL);
		}
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
	}
	tab[i].str = 0;
	return (tab);
}
