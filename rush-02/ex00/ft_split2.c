/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:33:57 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/24 14:49:22 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_remove_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (i != 0)
		str[i] = '\0';
	return (str);
}

char	*ft_remove_space2(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == 32 && str[i])
			i++;
		while (str[i] >= 33 && str[i] <= 126 && str[i])
		{
			str[k] = str[i];
			i++;
			k++;
		}
		if (k != 0 && str[i])
		{
			str[k] = ' ';
			k++;
		}
	}
	str[k] = '\0';
	return (str);
}

char	**ft_split2(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
	{
		if (i % 2 == 0)
			strs[i] = ft_remove_space(strs[i]);
		else if (i % 2 == 1)
			strs[i] = ft_remove_space2(strs[i]);
	}
	return (strs);
}
