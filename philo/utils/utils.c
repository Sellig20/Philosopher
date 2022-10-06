/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:51:53 by jecolmou          #+#    #+#             */
/*   Updated: 2022/10/01 21:03:21 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

void	ft_has_died(t_philo *philo, int index)
{
	pthread_mutex_lock(&(philo->data->message));
	pthread_mutex_lock(&(philo->data->die_mutex));
	printf("%lld %d has died\n", ft_get_time() - philo->tstart, index + 1);
	philo->data->status = 0;
	pthread_mutex_unlock(&(philo->data->die_mutex));
	pthread_mutex_unlock(&(philo->data->message));
}

void	ft_return_tmp(t_philo *philo, int tmp, int i)
{
	pthread_mutex_lock(&(philo->data->momutex)[i]);
	tmp = (philo->data->tab_monito)[i];
	pthread_mutex_unlock(&(philo->data->momutex)[i]);
}

void	ft_init_int(int index, int tmp, int old_eating_time)
{
	index = 0;
	tmp = 0;
	old_eating_time = 0;
}

void	ft_monitoring_annex(t_philo *philo)
{
	if (!ft_check_status(philo))
		return ;
	usleep(500);
}
