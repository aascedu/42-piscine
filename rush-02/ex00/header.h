/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgeffroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:20:24 by hgeffroy          #+#    #+#             */
/*   Updated: 2022/07/24 22:01:07 by hgeffroy         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *nb);
char	**ft_malloc(char **data, int magnitude);
char	**fill_hundred(char *nb, char **data);
char	**data_sort_hundred(char *nb, int magnitude);
char	*nb_setup(char *nb, int len_nb);
char	**data_sort(char *nb);
char	**ft_malloc(char **data, int magnitude);
void	puterror(int n);
int		check_args(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);
int		is_numeric(char *str);
char	**ft_split2(char **strs);
char	*ft_remove_space(char *str);
char	*ft_remove_space2(char *str);
int		ft_sep(char c, char *charset);
int		ft_count_args(char *str, char *charset);
char	*ft_strdup(char *str, char *charset);
char	**ft_split(char *str, char *charset);
int		ft_buffer_size(char *filename);
char	*ft_copy(char *filename);
int		ft_count_lines(char *str);
void	ft_display(char **str, char **tab);
int		ft_count_str(char **strs);
void	ft_putstr(char *str);
int		is_numeric(char *str);

#endif
