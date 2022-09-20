/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:09:15 by jecolmou          #+#    #+#             */
/*   Updated: 2022/09/20 23:30:28 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_exit(t_philo *philo, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < philo->data->num_philo)
	{
		pthread_join(philo[j].thread, NULL);
		j++;
	}
	i = data->num_philo - 1;
	while (i > 0)
	{
		pthread_mutex_destroy(&philo->data->chop_mutex[i]);
		i--;
	}
	pthread_mutex_destroy(&philo->data->eat_mutex);
	pthread_mutex_destroy(&philo->data->die_mutex);
	pthread_mutex_destroy(&philo->data->message);
	free(data->tab_meal);
	free(data->chop_mutex);
	free(data);
	free(philo);
	return ;
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	int		i;

	i = 0;
	data = malloc(sizeof(t_data));
	ft_bzero(data, sizeof(data));
	data->status = 0;
	if (ft_parse(argc, argv, i, data) == 0)
		return (free(data), 1);
	if (!data)
		return (1);
	if (ft_settle_variables(argv, data) == 0)
		return (free(data->tab_meal), free(data), 1);
	philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!philo)
		return (free(data), 1);
	ft_init_philo(philo, data);
	if (ft_init_mutex(data) == 0)
		return (free(data), free (philo), ft_putstr_fd("Error mutex\n", 2), 1);
	ft_init_thread(philo);
	ft_exit(philo, data);
	return (0);
}
