/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 21:36:41 by hgeffroy          #+#    #+#             */
/*   Updated: 2022/07/24 22:02:49 by hgeffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	char	**tab;
	char	**strs;

	if (check_args(argc, argv) == 0)
	{
		puterror(0);
		return (0);
	}
	if (argc == 2)
	{
		tab = ft_split(ft_copy("numbers.dict"), ":\n");
		tab = ft_split2(tab);
		strs = data_sort(argv[1]);
	}
	else if (argc == 3)
	{
		tab = ft_split(ft_copy(argv[1]), ":\n");
		strs = data_sort(argv[2]);
	}
	else
		return (0);
	ft_display(tab, strs);
	return (0);
}
