/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:13:46 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/14 18:27:46 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putargv(int argc, char **str)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (i < argc)
	{
		k = 0;
		while (str[i][k] != '\0')
		{
			write(1, &str[i][k], 1);
			k++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		k;
	char	*temp;

	i = 1;
	while (i < argc)
	{
		k = 1;
		while (k < argc)
		{
			if (ft_strcmp(argv[i], argv[k]) < 0)
			{
					temp = argv[i];
					argv[i] = argv[k];
					argv[k] = temp;
			}
			k++;
		}		
		i++;
	}
	ft_putargv(argc, argv);
	return (0);
}
