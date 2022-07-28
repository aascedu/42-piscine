/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 09:09:07 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/28 13:47:33 by aascedu          ###   ########lyon.fr   */
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

int	ft_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_args(char *str, char *charset)
{
	int	i;
	int	args;

	args = 0;
	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (ft_sep(str[i], charset) == 0)
				args++;
		}
		else
		{
			if (!ft_sep(str[i], charset) && ft_sep(str[i - 1], charset) == 1)
				args++;
		}
		i++;
	}
	return (args);
}

char	*ft_strdup(char *str, char *charset)
{
	int		i;
	char	*copy;

	i = 0;
	while (str[i] && ft_sep(str[i], charset) == 0)
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (str[i] && ft_sep(str[i], charset) == 0)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		arg;

	result = malloc(sizeof(char *) * (ft_count_args(str, charset) + 1));
	if (!result)
		return (NULL);
	i = 0;
	arg = 0;
	while (str[i])
	{
		if (ft_sep(str[i], charset) == 0)
		{
			result[arg++] = ft_strdup(&str[i], charset);
			while (str[i] && ft_sep(str[i], charset) == 0)
				i++;
		}
		if (str[i])
			i++;
	}
	result[arg] = NULL;
	return (result);
}
