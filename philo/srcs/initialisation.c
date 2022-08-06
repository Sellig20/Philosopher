/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:22:28 by jecolmou          #+#    #+#             */
/*   Updated: 2022/08/06 19:28:55 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_settle_variables(char **argv, t_data *data)
{
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
	else
		return (ft_putstr_fd("Error : wrong argument\n", 2), 0);
	data->time_start = ft_get_time();
	printf("FT GET TIME INIIIIIIt ==== %ld\n", ft_get_time());

	if (data->think < 0)
		return (ft_putstr_fd("ca va mourir parce que t'as pas le tmps de manger et dormir\n", 1), 0);
	return (1);
}

int	ft_init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = data->num_philo;
	while (--i >= 0)
	{
		philo[i].index = i + 1;
		philo[i].left_chpstck = i;
		philo[i].right_chpstck = (i + 1) % data->num_philo;
		philo[i].last_meal = ft_get_time();
		philo[i].meal_nb = 0;
		philo[i].data = data;
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
			ft_putstr_fd("Errorrr a pthread_create dans ft_routine\n", 2);
		i++;
	}
	i = 0;
	while (i < philo->data->num_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
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
	if (pthread_mutex_init(data->chop_mutex, NULL) == -1)
		return (free(data), 0);
	pthread_mutex_init(&data->message, NULL);
	if (pthread_mutex_init(&data->message, NULL) == -1)
		return (free(data), 0);
	pthread_mutex_init(&data->die_mutex, NULL);
	if (pthread_mutex_init(&data->die_mutex, NULL) == -1)
		return (free(data), 0);
	pthread_mutex_init(&data->eat_mutex, NULL);
	if (pthread_mutex_init(&data->eat_mutex, NULL) == -1)
		return (free(data), 0);
	return (1);
}
