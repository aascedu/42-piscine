/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancastan <ancastan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:39:07 by hgeffroy          #+#    #+#             */
/*   Updated: 2022/07/24 22:00:29 by hgeffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	puterror(int n)
{
	if (n == 0)
		write (1, "Error\n", 6);
	if (n == 1)
		write (1, "Dict Error\n", 11);
}

int	is_numeric(char	*str)
{
	unsigned int	i;
	unsigned int	a;

	a = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			a++;
		i++;
	}
	if (a != i)
		return (-1);
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		puterror(0);
	if (argc == 2 && is_numeric(argv[1]) == -1)
		puterror(0);
	if (argc == 3 && is_numeric(argv[2]) == -1)
		puterror(0);
	return (1);
}
