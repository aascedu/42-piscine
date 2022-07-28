/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:54:55 by hgeffroy          #+#    #+#             */
/*   Updated: 2022/07/25 09:12:28 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *nb)
{
	int	count;

	count = 0;
	while (nb[count])
		count++;
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len_dest;

	i = 0;
	len_dest = ft_strlen(dest);
	while (src[i] != 0)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = 0;
	return (dest);
}

char	**ft_malloc(char **data, int magnitude)
{
	int	i;

	data = malloc(sizeof(char *) * 5);
	if (!data)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		data[i] = malloc(sizeof(char) * 4);
		if (!data[i])
			return (NULL);
		i++;
	}
	data[4] = malloc(sizeof(char) * magnitude);
	if (!data[4])
		return (NULL);
	return (data);
}
