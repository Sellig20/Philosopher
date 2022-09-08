/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:24:20 by jecolmou          #+#    #+#             */
/*   Updated: 2022/09/08 10:00:17 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_take_chopsticks(t_philo *arendt)
{
	int	i;
	int	chopstick;

	i = 0;
	while (i < 2)
	{
		if (i == 0)
			chopstick = arendt->left_chpstck;
		else
			chopstick = arendt->right_chpstck;
		pthread_mutex_lock(&arendt->data->chop_mutex[chopstick]);
		pthread_mutex_lock(&arendt->data->message);
		printf("%ld %d philo is taking a chopstick !\n", (ft_get_time()
				- arendt->data->time_start), arendt->index);
		pthread_mutex_unlock(&arendt->data->message);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_mutex);
	ft_take_chopsticks(philo);
	philo->last_meal = ft_get_time();
	pthread_mutex_lock(&philo->data->message);
	printf("%ld %d philo is eating\n", (ft_get_time()
			- philo->data->time_start), philo->index);
	pthread_mutex_unlock(&philo->data->message);
	philo->data->tab_meal[philo->index -1]++;
	pthread_mutex_lock(&philo->data->die_mutex);
	ft_tab_meal(philo);
	pthread_mutex_unlock(&philo->data->die_mutex);
	pthread_mutex_unlock(&philo->data->eat_mutex);
	usleep(philo->data->teat * 1000);
	pthread_mutex_unlock(&philo->data->chop_mutex[philo->left_chpstck]);
	pthread_mutex_unlock(&philo->data->chop_mutex[philo->right_chpstck]);
}

void	ft_is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->message);
	printf("%ld %d philo is sleeping\n", (ft_get_time()
			- philo->data->time_start), philo->index);
	pthread_mutex_unlock(&philo->data->message);
	usleep(philo->data->tsleep * 1000);
}

void	ft_is_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->message);
	pthread_mutex_unlock(&philo->data->message);
	if (philo->data->teat * 2 > philo->data->tdeath)
		usleep (((philo->data->tdeath + 1)
				- (philo->data->teat + philo->data->tsleep)) * 1000);
}

void	ft_tab_meal(t_philo *philo)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	(void)index;
	if (philo->data->nb_meal >= 0)
	{
		while (philo->data->tab_meal[i] >= philo->data->nb_meal)
		{
			if (i == philo->data->num_philo - 1)
			{
				philo->data->status = 1;
				return ;
			}
			i++;
		}
	}
}
