/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_proc_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancastan <ancastan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:43:07 by hgeffroy          #+#    #+#             */
/*   Updated: 2022/07/24 19:56:14 by hgeffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**fill_hundred(char *nb, char **data)
{
	if (nb[0] > '0')
	{
		data[0][0] = nb[0];
		data[0][1] = '\0';
		data[1] = "100\0";
	}
	if (nb[1] > '1')
	{
		data[2][0] = nb[1];
		data[2][1] = '0';
		data[2][2] = '\0';
	}
	else if (nb[1] > '0')
	{
		data[2][0] = nb[1];
		data[2][1] = nb[2];
		data[2][2] = '\0';
	}
	if (nb[2] > '0' && nb[1] != '1')
	{
		data[3][0] = nb[2];
		data[3][1] = '\0';
	}
	return (data);
}

char	**data_sort_hundred(char *nb, int magnitude)
{
	char	**data;
	int		i;

	data = NULL;
	data = ft_malloc(data, magnitude);
	data = fill_hundred(nb, data);
	if (magnitude > 0 && (nb[0] != '0' || nb[1] != '0' || nb[2] != '0'))
	{
		i = 0;
		while (++i <= magnitude)
		{
			data[4][0] = '1';
			data[4][i] = '0';
		}
		data[4][i] = '\0';
	}
	return (data);
}

char	*nb_setup(char *nb, int len_nb)
{
	char	*nbdup;

	nbdup = malloc(sizeof(char) * (len_nb + 3));
	if (len_nb % 3 == 1)
	{
		nbdup[0] = '0';
		nbdup[1] = '0';
		nbdup = ft_strcat(nbdup, nb);
	}
	else if (len_nb % 3 == 2)
	{
		nbdup[0] = '0';
		nbdup = ft_strcat(nbdup, nb);
	}
	return (nbdup);
}

char	**data_zero(char **data)
{
	data[0] = malloc(sizeof(char) * 2);
	data[0][0] = '0';
	data[0][1] = '\0';
	data[1] = NULL;
	return (data);
}

char	**data_sort(char *nb)
{
	char	**data;
	int		mag;
	int		i;
	int		j;

	data = malloc(sizeof(char *) * (ft_strlen(nb) * 2 + 3));
	if (nb[0] == '0' && ft_strlen(nb) == 1)
		return (data_zero(data));
	i = 0;
	if (ft_strlen(nb) % 3 != 0)
		nb = nb_setup(nb, ft_strlen(nb));
	while (i < ft_strlen(nb))
	{
		j = 0;
		while (j < 5)
		{
			mag = ft_strlen(nb) - ft_strlen(nb) % 3 - i - 3;
			data[((i / 3) * 5) + j] = malloc(sizeof(char) * 50);
			data[((i / 3) * 5) + j] = data_sort_hundred(&nb[i], mag)[j];
			j++;
		}
		i += 3;
	}
	data[(((i - 1) / 3) * 5) + j - 1] = NULL;
	return (data);
}
