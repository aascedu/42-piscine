/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:22:23 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/24 13:32:29 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// TROUVE LA TAILLE DU FICHIER
int	ft_buffer_size(char *filename)
{
	int		size;
	char	buffer;
	int		fd;

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &buffer, 1) > 0)
		size++;
	close(fd);
	return (size);
}

// COPIE NOTRE FICHIER DANS UNE STRING
char	*ft_copy(char *filename)
{
	int		fd;
	int		size;
	char	*buffer;

	size = ft_buffer_size(filename);
	buffer = malloc(size + 1);
	if (!buffer)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	read(fd, buffer, size);
	return (buffer);
}

// COMPTE LE NOMBRE DE VRAIES LIGNES DE NOTRE DICO
int	ft_count_lines(char *str)
{
	int	i;
	int	nb_lines;

	nb_lines = 0;
	i = -1;
	while (str[++i])
		if (i != 0 && str[i] == '\n' && str[i - 1] != '\n')
			nb_lines++;
	return (nb_lines);
}
