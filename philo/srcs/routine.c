/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:00:27 by jecolmou          #+#    #+#             */
/*   Updated: 2022/09/21 00:29:42 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->chop_mutex[philo->right_chpstck]);
	pthread_mutex_unlock(&philo->data->chop_mutex[philo->left_chpstck]);
	return (0);
}

int	ft_check_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->die_mutex);
	if (philo->data->status == 1)
	{
		pthread_mutex_unlock(&philo->data->die_mutex);
		return (1);
	}
	if ((ft_get_time() - philo->last_meal) > philo->data->tdeath)
		philo->data->status = 2;
	if (philo->data->status == 0)
	{
		pthread_mutex_unlock(&philo->data->die_mutex);
		return (0);
	}
	else if (philo->data->status == 2)
	{
		pthread_mutex_lock(&philo->data->message);
		printf("%ld %d died\n", (ft_get_time()
				- philo->data->time_start), philo->index);
		pthread_mutex_unlock(&philo->data->message);
		philo->data->go_death = 1;
		philo->data->status = 1;
		pthread_mutex_unlock(&philo->data->die_mutex);
		return (1);
	}
	return (0);
}

void	*ft_habit(void *socrate)
{
	t_philo	*kant;

	kant = (t_philo *)socrate;
	if (kant->index % 2)
		usleep(15 * 1000);
	while (1)
	{
		if (ft_check_status(kant) != 0)
			return (NULL);
		ft_is_eating(kant);
		if (ft_check_status(kant) != 0)
			return (NULL);
		ft_is_sleeping(kant);
		if (ft_check_status(kant) != 0)
			return (NULL);
		ft_is_thinking(kant);
		if (ft_check_status(kant) != 0)
			return (NULL);
	}
}
