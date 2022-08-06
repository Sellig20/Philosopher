/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:39:51 by jecolmou          #+#    #+#             */
/*   Updated: 2022/08/06 17:06:01 by jecolmou         ###   ########.fr       */
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
#include <pthread.h>

#define EXIT_OK 1
#define EXIT_ERROR 0

//////////STRUCTURE/////////

typedef struct s_philo		t_philo;

typedef struct s_data		t_data;

struct s_philo
{
	int	index;
	int left_chpstck;
	int right_chpstck;
	int last_meal;
	int	meal_nb;
	int	eat;
	pthread_t	thread;
	t_data	*data;
};

struct s_data
{
	int num_philo;
	int num_chopstick;

	int	chopsticks;

	int	phil;
	int	tdeath;
	int	teat;
	int	tsleep;
	int	nb_meal;
	int	think;

	pthread_mutex_t message;
	pthread_mutex_t *chop_mutex;
	pthread_mutex_t die_mutex;
	pthread_mutex_t	eat;
};

//////////PARSING//////////
int	ft_check_args(int argc, char **argv);
int	ft_check_digit(char	**argv);
int	ft_parse(int argc, char **argv, int i, t_data *data);

//////////SRCS//////////
int	ft_init_mutex(t_data *data);
int	ft_init_philo(t_philo *philo, t_data *data);
int	ft_settle_variables(char **argv, t_data *data);
void	ft_routine(t_philo *philo);
void	*ft_habit(void *socrate);
int	ft_take_chopsticks(t_philo *arendt);
int ft_chopstick_back(t_philo *nietzsche);
int	ft_eat(t_philo *aristote);
int	ft_is_dead(t_philo *platon);

//////////UTILS//////////
int		ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
long long	ft_atol(char *str);
long ft_get_time(void);

#endif