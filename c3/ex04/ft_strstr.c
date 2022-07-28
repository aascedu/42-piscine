/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:05:26 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/28 08:19:32 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_char_match(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (str[i] == to_find[i] && to_find[i])
		i++;
	if (to_find[i] == 0)
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	if (ft_strlen(str) < ft_strlen(to_find))
		return (0);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			if (ft_char_match(&str[i], to_find) == 1)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
