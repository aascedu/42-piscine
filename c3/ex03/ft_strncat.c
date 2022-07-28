/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:28:55 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/14 19:27:01 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				size;
	unsigned int	i;

	size = 0;
	while (dest[size] != '\0')
		size++;
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[i + size] = src[i];
		i++;
	}
	dest[i + size] = '\0';
	return (dest);
}
