/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:24:20 by jecolmou          #+#    #+#             */
/*   Updated: 2022/08/06 19:34:05 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	ft_is_dead(t_philo *philo)
{
	/*si a chaque gettime + tdeath il n'a pas mange*/
	if (philo->eat <= philo->data->tdeath)
	{
		pthread_mutex_lock(&philo->data->message);
		ft_putstr_fd("PHILO DEAD\n", 1);
		pthread_mutex_unlock(&philo->data->message);
	}
}

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
		printf("time = %ld et %d philo is taking a chopstick !\n", (ft_get_time() - arendt->data->time_start), arendt->index);
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
		printf("TIME START = %ld\n", philo->data->time_start);
	printf("FT GET TIME ==== %ld\n", ft_get_time());

	printf("time = %ld et %d philo is eating\n", (ft_get_time() - philo->data->time_start), philo->index);
	pthread_mutex_unlock(&philo->data->message);

	pthread_mutex_unlock(&philo->data->eat_mutex);
	usleep(philo->data->teat * 1000);

	pthread_mutex_unlock(&philo->data->chop_mutex[philo->left_chpstck]);
	pthread_mutex_unlock(&philo->data->chop_mutex[philo->right_chpstck]);

}

void	ft_is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->message);
	printf("time = %ld et %d philo is sleeping\n", (ft_get_time() - philo->data->time_start), philo->index);
	pthread_mutex_unlock(&philo->data->message);
}


void	ft_is_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->message);
	printf("time = %ld et %d philo is thinking\n", (ft_get_time() - philo->data->time_start), philo->index);
	pthread_mutex_unlock(&philo->data->message);
}
