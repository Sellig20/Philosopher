/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:22:28 by jecolmou          #+#    #+#             */
/*   Updated: 2022/09/20 13:49:03 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_settle_variables(char **argv, t_data *data)
{
	int	i;

	i = -1;
	if (argv[2])
		data->tdeath = ft_atoi(argv[2]);
	if (argv[3])
		data->teat = ft_atoi(argv[3]);
	if (argv[4])
		data->tsleep = ft_atoi(argv[4]);
	if (argv[5])
		data->nb_meal = ft_atoi(argv[5]);
	else if (argv[5] == NULL)
		data->nb_meal = -1;
	else if (data->tdeath < 0 || data->teat < 0 || data->tsleep < 0)
		return (ft_putstr_fd("Error : Invalid argument\n", 2), 0);
	else
		return (ft_putstr_fd("Error : wrong argument\n", 2), 0);
	data->time_start = ft_get_time();
	data->tab_meal = malloc(sizeof(int) * data->num_philo);
	if (!data->tab_meal)
		return (0);
	while (++i < data->num_philo)
		data->tab_meal[i] = 0;
	return (1);
}

int	ft_init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		philo[i].index = i + 1;
		philo[i].left_chpstck = (i + i % 2) % data->num_philo;
		philo[i].right_chpstck = (i + 1 - i % 2) % data->num_philo;
		philo[i].last_meal = ft_get_time();
		philo[i].meal_nb = 0;
		philo[i].data = data;
		i++;
	}
	return (EXIT_OK);
}

void	ft_init_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_philo)
	{
		pthread_create(&philo[i].thread, NULL, ft_habit, &philo[i]);
		if (!philo[i].thread)
			ft_putstr_fd("Error : pthread_create\n", 2);
		i++;
	}
	i = 0;
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->chop_mutex = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->chop_mutex)
		return (0);
	while (i < data->num_philo)
	{
		pthread_mutex_init(&data->chop_mutex[i], NULL);
		i++;
	}
	if (pthread_mutex_init(&data->message, NULL) == -1)
		return (free(data), 0);
	if (pthread_mutex_init(&data->die_mutex, NULL) == -1)
		return (free(data), 0);
	if (pthread_mutex_init(&data->eat_mutex, NULL) == -1)
		return (free(data), 0);
	return (1);
}
