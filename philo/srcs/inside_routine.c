/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:24:20 by jecolmou          #+#    #+#             */
/*   Updated: 2022/09/21 00:46:08 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_take_chopsticks(t_philo *arendt)
{
	pthread_mutex_lock(&arendt->data->chop_mutex[arendt->left_chpstck]);
	if (ft_check_status(arendt) != 0)
	{
		pthread_mutex_unlock(&arendt->data->chop_mutex[arendt->left_chpstck]);
		return (0);
	}
	pthread_mutex_lock(&arendt->data->message);
	printf("%ld %d has taken a fork\n", (ft_get_time()
			- arendt->data->time_start), arendt->index);
	pthread_mutex_unlock(&arendt->data->message);
	pthread_mutex_lock(&arendt->data->chop_mutex[arendt->right_chpstck]);
	if (ft_check_status(arendt) != 0)
	{
		pthread_mutex_unlock(&arendt->data->chop_mutex[arendt->right_chpstck]);
		pthread_mutex_unlock(&arendt->data->chop_mutex[arendt->left_chpstck]);
		return (0);
	}
	pthread_mutex_lock(&arendt->data->message);
	printf("%ld %d has taken a fork\n", (ft_get_time()
			- arendt->data->time_start), arendt->index);
	pthread_mutex_unlock(&arendt->data->message);
	return (1);
}

int	ft_is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_mutex);
	ft_take_chopsticks(philo);
	philo->last_meal = ft_get_time();
	if (ft_check_status(philo) != 0)
		return (pthread_mutex_unlock(&philo->data->eat_mutex), 0);
	pthread_mutex_lock(&philo->data->message);
	printf("%ld %d is eating\n", (ft_get_time()
			- philo->data->time_start), philo->index);
	pthread_mutex_unlock(&philo->data->message);
	philo->data->tab_meal[philo->index -1]++;
	pthread_mutex_lock(&philo->data->die_mutex);
	ft_tab_meal(philo);
	pthread_mutex_unlock(&philo->data->die_mutex);
	pthread_mutex_unlock(&philo->data->eat_mutex);
	while (ft_get_time() < philo->last_meal + philo->data->teat)
	{
		if (ft_check_status(philo) != 0)
			return (ft_unlock(philo));
		usleep(500);
	}
	ft_unlock(philo);
	return (1);
}

void	ft_is_sleeping(t_philo *philo)
{
	long long int	sleep_time;

	if (ft_check_status(philo) != 0)
	{
		return ;
	}
	sleep_time = ft_get_time();
	pthread_mutex_lock(&philo->data->message);
	printf("%ld %d is sleeping\n", (ft_get_time()
			- philo->data->time_start), philo->index);
	pthread_mutex_unlock(&philo->data->message);
	while (ft_get_time() < sleep_time + philo->data->tsleep)
	{
		if (ft_check_status(philo) != 0)
			return ;
		usleep(500);
	}
}

void	ft_is_thinking(t_philo *philo)
{
	long long int	think_time;

	think_time = ft_get_time();
	if (ft_check_status(philo) != 0)
	{
		return ;
	}
	pthread_mutex_lock(&philo->data->message);
	printf("%ld %d is thinking\n", (ft_get_time()
			- philo->data->time_start), philo->index);
	pthread_mutex_unlock(&philo->data->message);
	while (ft_get_time() < think_time
		+ (philo->data->tdeath - philo->data->teat - philo->data->tsleep) / 2)
	{
		if (ft_check_status(philo) != 0)
			return ;
		usleep(500);
	}
}

void	ft_tab_meal(t_philo *philo)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	if (philo->data->nb_meal >= 0)
	{
		while (philo->data->tab_meal[index] >= philo->data->nb_meal)
		{
			if (i == philo->data->num_philo - 1)
			{
				philo->data->status = 1;
				return ;
			}
			i++;
			index++;
		}
	}
}
