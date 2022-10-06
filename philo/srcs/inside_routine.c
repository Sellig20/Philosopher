/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:24:20 by jecolmou          #+#    #+#             */
/*   Updated: 2022/10/03 14:14:05 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_take_chopsticks(t_philo *philo)
{
	pthread_mutex_lock(&((philo->data->chop_mutex)[philo->left_chpstck]));
	pthread_mutex_lock(&(philo->data->message));
	if (!ft_check_status(philo))
	{
		pthread_mutex_unlock(&(philo->data->chop_mutex[philo->left_chpstck]));
		pthread_mutex_unlock(&(philo->data->message));
		return (0);
	}
	printf("%lld %d has taken a fork\n", (ft_get_time()
			- philo->tstart), philo->index + 1);
	pthread_mutex_unlock(&(philo->data->message));
	pthread_mutex_lock(&(philo->data->chop_mutex[philo->right_chpstck]));
	pthread_mutex_lock(&(philo->data->message));
	if (!ft_check_status(philo))
	{
		ft_unlock(philo);
		pthread_mutex_unlock(&(philo->data->message));
		return (0);
	}
	printf("%lld %d has taken a fork\n", (ft_get_time()
			- philo->tstart), philo->index + 1);
	pthread_mutex_unlock(&(philo->data->message));
	return (1);
}

int	ft_is_eating(t_philo *phi)
{
	long long int	st_etime;

	st_etime = ft_get_time();
	pthread_mutex_lock(&((phi->data->momutex)[phi->index]));
	(phi->data->tab_monito)[phi->index] = st_etime;
	pthread_mutex_unlock(&((phi->data->momutex)[phi->index]));
	pthread_mutex_lock(&(phi->data->message));
	if (!ft_check_status(phi))
	{
		ft_unlock(phi);
		return (pthread_mutex_unlock(&(phi->data->message)), 0);
	}
	printf("%lld %d is eating\n", (st_etime - phi->tstart), phi->index + 1);
	pthread_mutex_unlock(&(phi->data->message));
	while (ft_get_time() < st_etime + phi->teat)
	{
		if (!ft_check_status(phi))
		{
			ft_unlock(phi);
			return (0);
		}
		usleep(500);
	}
	ft_unlock(phi);
	return (1);
}

int	ft_is_sleeping(t_philo *philo)
{
	long long int	start_sleeping_time;

	start_sleeping_time = ft_get_time();
	pthread_mutex_lock(&(philo->data->message));
	if (!ft_check_status(philo))
	{
		pthread_mutex_unlock(&(philo->data->message));
		return (0);
	}
	printf("%lld %d is sleeping\n", (start_sleeping_time
			- philo->tstart), philo->index + 1);
	pthread_mutex_unlock(&(philo->data->message));
	while (ft_get_time() < start_sleeping_time + philo->tsleep)
	{
		if (!ft_check_status(philo))
			return (0);
		usleep(500);
	}
	return (1);
}

int	ft_is_thinking(t_philo *philo)
{
	long long int	start_thinking_time;

	start_thinking_time = ft_get_time();
	pthread_mutex_lock(&(philo->data->message));
	if (!ft_check_status(philo))
	{
		pthread_mutex_unlock(&(philo->data->message));
		return (0);
	}
	printf("%lld %d is thinking\n", (start_thinking_time
			- philo->tstart), philo->index + 1);
	pthread_mutex_unlock(&(philo->data->message));
	while (ft_get_time() < start_thinking_time
		+ (philo->tdeath - philo->teat - philo->tsleep) / 2)
	{
		if (!ft_check_status(philo))
			return (0);
		usleep(500);
	}
	return (1);
}

int	ft_tab_meal(t_philo *philo)
{
	if (philo->nb_meal == -1)
		return (1);
	philo->eaten_meal_nb++;
	if (philo->eaten_meal_nb == philo->nb_meal)
	{
		pthread_mutex_lock(&(philo->data->full_mutex));
		(philo->data->full)++;
		if (philo->data->full == philo->num_philo)
		{
			pthread_mutex_lock(&(philo->data->die_mutex));
			philo->data->status = 0;
			pthread_mutex_unlock(&(philo->data->die_mutex));
			pthread_mutex_unlock(&(philo->data->full_mutex));
			return (0);
		}
		pthread_mutex_unlock(&(philo->data->full_mutex));
	}
	return (1);
}
