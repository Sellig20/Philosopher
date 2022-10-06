/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:22:28 by jecolmou          #+#    #+#             */
/*   Updated: 2022/10/03 15:48:20 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_settle_variables(char **argv, t_data *data)
{
	int	i;

	i = 0;
	data->tab_monito = malloc(sizeof(long long int) * ft_atoi(argv[1]));
	if (!data->tab_monito)
		return (0);
	return (1);
}

int	ft_init_philo(t_philo *philo, t_data *data, int i, char **argv)
{
	long long int	start_time;

	start_time = ft_get_time();
	if (argv[1])
		philo[i].num_philo = ft_atoi(argv[1]);
	if (argv[2])
		philo[i].tdeath = ft_atoi(argv[2]);
	if (argv[3])
		philo[i].teat = ft_atoi(argv[3]);
	if (argv[4])
		philo[i].tsleep = ft_atoi(argv[4]);
	if (argv[5])
		philo[i].nb_meal = ft_atoi(argv[5]);
	else if (argv[5] == NULL)
		philo[i].nb_meal = -1;
	philo[i].tstart = ft_get_time();
	philo[i].index = i;
	philo[i].left_chpstck = ((i + i % 2) % philo->num_philo);
	philo[i].right_chpstck = ((i + 1 - i % 2) % philo->num_philo);
	philo[i].meal_nb = 0;
	philo[i].data = data;
	philo[i].tstart = start_time;
	data->tab_monito[i] = start_time;
	return (EXIT_OK);
}

void	ft_init_thread(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->num_philo)
	{
		(&philo[i])->data = data;
		pthread_create(&(&philo[i])->thread, NULL, ft_habit, &philo[i]);
		if (!philo[i].thread)
			ft_putstr_fd("Error : pthread_create\n", 2);
		i++;
	}
	i = 0;
}

int	ft_init_mutex(t_data *data, t_philo *philo)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	data->chop_mutex = malloc(sizeof(pthread_mutex_t) * philo->num_philo);
	data->momutex = malloc(sizeof(pthread_mutex_t) * philo->num_philo);
	if (!data->chop_mutex || !data->tab_monito)
		return (0);
	while (++i < philo->num_philo)
		pthread_mutex_init(&((data->chop_mutex)[i]), NULL);
	while (++j < philo->num_philo)
		pthread_mutex_init(&((data->momutex)[j]), NULL);
	if (pthread_mutex_init(&(data->full_mutex), NULL) == -1)
		return (free(data), 0);
	if (pthread_mutex_init(&(data->message), NULL) == -1)
		return (free(data), 0);
	if (pthread_mutex_init(&(data->die_mutex), NULL) == -1)
		return (free(data), 0);
	return (1);
}
