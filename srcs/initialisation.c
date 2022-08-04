/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:22:28 by jecolmou          #+#    #+#             */
/*   Updated: 2022/08/04 18:35:33 by jecolmou         ###   ########.fr       */
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
	else
		return (ft_putstr_fd("Error : wrong argument\n", 2), 0);
	data->think = data->tdeath - (data->teat + data->tsleep);
	if (data->think < 0)
		return (ft_putstr_fd("ca va mourir parce que t'as pas le tmps de manger et dormir\n", 1), 0);
	return (1);
}

int	ft_init_philo(t_data *data)
{
	int	i;

	i = 1;
	data->rousseau = malloc(sizeof(t_philo) * (data->num_philo));
	if (!data->rousseau)
		return (0);
	// data->chopsticks = malloc(sizeof(t_philo) * (data->num_chopstick));
	// if (!data->chopsticks)
	// 	return (0);
	while (i <= data->num_philo)
	{
		data->rousseau->index = i;
		data->rousseau->left_chpstck = i;
		data->rousseau->right_chpstck = (i + 1) % data->num_philo;
		data->rousseau->last_meal = 0;
		data->rousseau->meal_nb = 0;
		i++;
	}
	return (EXIT_OK);
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->chop_mutex = malloc(sizeof(pthread_mutex_t) * data->num_chopstick);
	if (!data->chop_mutex)
		return (0);
	while (i < data->num_philo)
	{
		pthread_mutex_init(&data->chop_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->write_mutex, NULL);
	pthread_mutex_init(&data->die_mutex, NULL);
	return (1);
}
