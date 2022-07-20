/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannecolmou <jeannecolmou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:39:51 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/20 16:46:07 by jeannecolmo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

//////////STRUCTURE/////////
typedef struct s_philo		t_philo;

struct s_philo
{
	int	index;
	int left_chpstck;
	int right_chpstck;
	int last_meal;
};


typedef struct s_data		t_data;

struct s_data
{
	int num_philo;
	int num_chopstick;

	t_philo *rousseau;
	int	chopsticks;

	int	phil;
	int	tdeath;
	int	teat;
	int	tsleep;
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
