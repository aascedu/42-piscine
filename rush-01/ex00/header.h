/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:58:13 by aascedu           #+#    #+#             */
/*   Updated: 2022/07/17 18:53:03 by abruere          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <unistd.h>

int		ft_check_input(char *str);
int		ft_check_tem(int ***tab, int a, int b, int n);
void	ft_display(int **tab, int n);
int		**ft_malloc2(int n);
int		***ft_malloc3(int n);
int		**ft_create_input(int *tab, int n);
int		**ft_my_atoi(char *str, int n);
int		***ft_possible(int **input, int **tab, int n);
void	ft_puterror(void);
#endif
