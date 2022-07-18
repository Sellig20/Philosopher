/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannecolmou <jeannecolmou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:39:51 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/18 15:27:07 by jeannecolmo      ###   ########.fr       */
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
	int num_philo;

	int	phil;
	int	death;
	int	eat;
	int	sleep;
	int	think;
};

//////////PARSING//////////
int	ft_check_args(int argc, char **argv);
int	ft_check_digit(int argc, char	**argv, int i);
int	ft_parse(int argc, char **argv, int i, t_data *data);

//////////SRCS//////////

//////////UTILS//////////
int		ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *str);

#endif
