/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:00:27 by jecolmou          #+#    #+#             */
/*   Updated: 2022/09/08 10:00:43 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_check_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->die_mutex);
	if (philo->data->status == 1)
	{
		pthread_mutex_unlock(&philo->data->die_mutex);
		return (-1);
	}
	if ((ft_get_time() - philo->last_meal) > philo->data->tdeath)
	{
		printf("%ld %d has died", (ft_get_time()
				- philo->data->time_start), philo->index);
		philo->data->status = 1;
		pthread_mutex_unlock(&philo->data->die_mutex);
		return (-1);
	}
	if (philo->data->status == 0)
	{
		pthread_mutex_unlock(&philo->data->die_mutex);
		return (0);
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
