/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:39:51 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/19 16:00:31 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
#include <unistd.h>
#include <limits.h>

//////////STRUCTURE/////////
typedef struct s_data		t_data;

struct s_data
{
	int num_philo;
	int num_chopstick;

	int	phil;
	int	death;
	int	eat;
	int	sleep;
	int	think;
};

//////////PARSING//////////
int	ft_check_args(int argc, char **argv);
int	ft_check_digit(char	**argv);
int	ft_parse(int argc, char **argv, int i, t_data *data);

//////////SRCS//////////

//////////UTILS//////////
int		ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
long long	ft_atol(char *str);

#endif
