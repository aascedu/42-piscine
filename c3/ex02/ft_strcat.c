/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:45:35 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/11 19:04:05 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	size;
	int	i;

	size = 0;
	while (dest[size])
		size++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[i + size] = src[i];
		i++;
	}
	dest[i + size] = '\0';
	return (dest);
}
