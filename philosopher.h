/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:39:51 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/13 18:10:37 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
#include <unistd.h>

//////////STRUCTURE/////////
typedef struct s_data		t_data;

struct s_data
{
	int	phil;
	int	death;
	int	eat;
	int	sleep;
	int	think;
};

//////////PARSING//////////
int	ft_check_args(int argc, char **argv);
int	ft_check_digit(char	**argv, int i);
int	ft_parse(int argc, char **argv, int i);

//////////SRCS//////////
int	ft_check_digit(char	**argv, int i);

//////////UTILS//////////
int		ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif
