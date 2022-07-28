/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:05:53 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/13 14:20:26 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 0;
	if (nb == 0)
		return (1);
	else
	{
		i = nb;
		while (--i > 0)
			nb = nb * i;
		return (nb);
	}
}
