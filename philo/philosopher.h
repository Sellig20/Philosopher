/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:39:51 by jecolmou          #+#    #+#             */
/*   Updated: 2022/10/01 21:07:14 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <inttypes.h>
# include <math.h>
# include <stdio.h>
# include <time.h>
# include <sys/time.h>
# include <pthread.h>

# define EXIT_OK 1
# define EXIT_ERROR 0

//////////STRUCTURE/////////

typedef struct s_monito		t_monito;

struct	s_monito
{
	long long int	old_eating_time;
	long long int	tmp;
	int				i;
	int				index;
};

typedef struct s_data
{
	int				status;
	int				full;
	long long int	*tab_monito;
	pthread_mutex_t	*momutex;
	pthread_mutex_t	message;
	pthread_mutex_t	*chop_mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	full_mutex;
}					t_data;

typedef struct s_philo
{
	int				index;
	int				left_chpstck;
	int				right_chpstck;
	int				meal_nb;
	int				eaten_meal_nb;
	int				eat;
	long long int	tdeath;
	int				teat;
	int				tsleep;
	int				num_philo;
	int				nb_meal;
	long long int	tstart;
	pthread_t		thread;
	t_data			*data;
}					t_philo;

//////////PARSING//////////
int			ft_check_args(int argc, char **argv);
int			ft_check_digit(char	**argv);
int			ft_parse(int argc, char **argv, t_data *data);
int			ft_isdigit(int c);
int			ft_isnum(char *num);
int			ft_get_num_philo(char **argv, t_data *data);

//////////SRCS//////////

int			ft_settle_variables(char **argv, t_data *data);
int			ft_take_chopsticks(t_philo *arendt);
int			ft_is_eating(t_philo *philo);
int			ft_is_sleeping(t_philo *philo);
int			ft_is_thinking(t_philo *philo);
int			ft_tab_meal(t_philo *philo);
int			ft_monitoring(t_philo *philo);
int			ft_init_mutex(t_data *data, t_philo *philo);
int			ft_init_philo(t_philo *philo, t_data *data, int i, char **argv);
void		ft_init_thread(t_philo *philo, t_data *data);
void		*ft_habit(void *socrate);
int			ft_take_chopsticks(t_philo *philo);
void		ft_chopstick_back(t_philo *philo);
int			ft_is_eating(t_philo *philo);
int			ft_check_status(t_philo *philo);

//////////UTILS//////////
int			ft_strlen(char *str);
void		ft_bzero(void *s, size_t n);
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *str);
long long	ft_atol(char *str);
long long	ft_get_time(void);
int			ft_unlock(t_philo *philo);
void		ft_has_died(t_philo *philo, int index);
void		ft_return_tmp(t_philo *philo, int tmp, int i);
void		ft_init_int(int index, int tmp, int old_eating_time);
void		ft_monitoring_annex(t_philo *philo);
#endif
