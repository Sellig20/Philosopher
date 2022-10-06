/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:09:15 by jecolmou          #+#    #+#             */
/*   Updated: 2022/10/03 15:41:03 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_exit(t_philo *philo, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < philo->num_philo)
	{
		pthread_join(philo[j].thread, NULL);
		j++;
	}
	i = philo->num_philo;
	while (--i > 0)
		pthread_mutex_destroy(&(philo->data->chop_mutex[i]));
	i = philo->num_philo;
	while (--i > 0)
		pthread_mutex_destroy(&(philo->data->momutex[i]));
	pthread_mutex_destroy(&(philo->data->full_mutex));
	pthread_mutex_destroy(&(philo->data->die_mutex));
	pthread_mutex_destroy(&(philo->data->message));
	free(data->chop_mutex);
	free(data->momutex);
	free(data->tab_monito);
	free(data);
	free(philo);
	return ;
}

int	ft_monitoring(t_philo *philo)
{
	t_monito	x;

	ft_bzero(&x, sizeof(x));
	while (1)
	{
		x.i = -1;
		while (++x.i < philo->num_philo)
		{
			ft_return_tmp(philo, x.tmp, x.i);
			if (!x.i || x.tmp < x.old_eating_time)
			{
				x.old_eating_time = x.tmp;
				x.index = x.i;
			}
		}
		usleep(500);
		while (ft_get_time() < x.old_eating_time + philo->tdeath)
			ft_monitoring_annex(philo);
		pthread_mutex_lock(&(philo->data->momutex)[x.index]);
		x.tmp = (philo->data->tab_monito)[x.index];
		pthread_mutex_unlock(&(philo->data->momutex)[x.index]);
		if (x.tmp == x.old_eating_time)
			return (ft_has_died(philo, x.index), 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	int		i;

	i = -1;
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	ft_bzero(data, sizeof(data));
	data->status = 1;
	if (ft_parse(argc, argv, data) == 0)
		return (free(data), 1);
	philo = malloc(sizeof(t_philo) * (ft_atoi(argv[1]) + 1));
	if (!philo)
		return (free(data), 1);
	if (ft_settle_variables(argv, data) == 0)
		return (free(data), 1);
	while (++i < ft_atoi(argv[1]))
		ft_init_philo(philo, data, i, argv);
	if (ft_init_mutex(data, philo) == 0)
		return (free(data), free (philo), ft_putstr_fd("Error mutex\n", 2), 1);
	ft_init_thread(philo, data);
	ft_monitoring(philo);
	ft_exit(philo, data);
	return (0);
}
