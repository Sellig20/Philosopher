/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannecolmou <jeannecolmou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:09:15 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/25 11:14:42 by jeannecolmo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// int	ft_check_death(char	**argv, t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (argv[i][j])
// 	{
		
// 	}
// }


// int	ft_un_alloc(t_data *data)
// {
// 	if ()
// }


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
		printf("philo numero %d\n", data->rousseau->index);
		printf("left chop = %d\n", data->rousseau->left_chpstck);
		printf("right chop = %d\n", data->rousseau->right_chpstck);
		printf("last meal = %d\n", data->rousseau->last_meal);
		printf("----------------------------------\n");
		i++;
	}
	return (1);
}

int	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * data->num_chopstick);
	if (!data->forks_mutex)
		return (0);
	while (i < data->num_philo)
	{
		pthread_mutex_init(&data->forks_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->write_mutex, NULL);
	pthread_mutex_init(&data->die_mutex, NULL);
	return (1);
}

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
	return (1);
}

long ft_get_time(void)
{
	struct timeval  tv;
	gettimeofday(&tv, NULL);

	long time_in_mill = 
			(tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
	return (time_in_mill);
}

int main(int argc, char **argv)
{
	t_data	data;
	int	i;

	i = 0;
	int time_in_mill = ft_get_time();
	printf("time = %d\n", time_in_mill);
	printf("------------------------\n");
	ft_bzero(&data, sizeof(data));

	if (ft_parse(argc, argv, i, &data) == 0)
		return (1);
	if (ft_settle_variables(argv, &data) == 0)
		return (1);

	if (ft_init_mutex(&data) == 0)
		return (ft_putstr_fd("Error de init mutex\n", 2), 1);
	printf("num philo = %d\n", data.num_philo);
	printf("num chops = %d\n", data.num_chopstick);
	printf("time death = %d\n", data.tdeath);
	printf("time eat = %d\n", data.teat);
	printf("time sleep = %d\n", data.tsleep);
	printf("num meal = %d\n", data.nb_meal);
	printf("-------------------------\n");
	ft_init_philo(&data);

	return (0);
}

