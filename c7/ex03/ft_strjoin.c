/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:31:57 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/28 13:50:20 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strslen(char **strs, int size)
{
	int	i;
	int	length;

	i = -1;
	length = 0;
	while (++i < size)
		length = length + ft_len(strs[i]);
	return (length);
}

int	ft_secure_malloc(char **dest, char **strs, char *sep, int size)
{
	int	s;

	s = sizeof(char);
	if (size > 0)
	{
		(*dest) = malloc(s * (ft_strslen(strs, size)
					+ (ft_len(sep) * (size - 1)) + 1));
		if (!(*dest))
			return (0);
	}
	else
	{
		(*dest) = malloc(s);
		if (!(*dest))
			return (0);
	}
	return (1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		k;
	int		j;

	if (ft_secure_malloc(&dest, strs, sep, size) == 0)
		return (NULL);
	i = -1;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (k < ft_len(strs[i]))
			dest[k++] = strs[i][j++];
		j = 0;
		while (sep[k] && i < size - 1)
			dest[k++] = sep[j++];
	}
	dest[k] = '\0';
	return (dest);
}
