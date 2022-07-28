/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:28:06 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/17 19:39:54 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	int	n;
	int	**input;
	int	**tab;
	int	***tem;

	n = 4;
	if (argc != 2)
		ft_puterror();
	else if (ft_check_input(argv[1], n) == 0)
		ft_puterror();
	else
	{
		input = ft_my_atoi(argv[1], n);
		tab = ft_start(input, n);
		tem = ft_possible(input, tab, n);
		ft_display(tab, n);
	}
	return (0);
}
