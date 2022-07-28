/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:08:42 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/26 23:07:24 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	max;
	int	min;
	int	avg;

	max = 46341;
	min = 0;
	while (max - min > 1)
	{
		avg = (max + min) / 2;
		if (avg * avg > nb)
			max = avg;
		else if (avg * avg < nb)
			min = avg;
		else
			return (avg);
	}
	return (0);
}
