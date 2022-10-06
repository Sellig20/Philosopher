/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:00:27 by jecolmou          #+#    #+#             */
/*   Updated: 2022/10/04 20:29:55 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->data->chop_mutex[philo->right_chpstck]));
	pthread_mutex_unlock(&(philo->data->chop_mutex[philo->left_chpstck]));
	return (0);
}

int	ft_check_status(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&(philo->data->die_mutex));
	ret = philo->data->status;
	pthread_mutex_unlock(&(philo->data->die_mutex));
	return (ret);
}

void	*ft_habit(void *socrate)
{
	t_philo	*kant;

	kant = (t_philo *)socrate;
	if (kant->num_philo == 1)
	{
		printf("%d %d has taken a fork\n", 0, 1);
		usleep(((int)kant->tdeath) * 1000);
		return (NULL);
	}
	while (1)
	{
		if (!ft_take_chopsticks(kant) \
			|| !ft_is_eating(kant) \
			|| !ft_tab_meal(kant) \
			|| !ft_is_sleeping(kant) \
			|| !ft_is_thinking(kant))
			return (NULL);
	}
	return (NULL);
}
