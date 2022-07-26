
#include "philosopher.h"

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
	return (EXIT_OK);
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
		pthread_mutex_init(&data->chop_mutex[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->write_mutex, NULL);
	pthread_mutex_init(&data->die_mutex, NULL);
	return (1);
}

int	ft_is_dead(t_philo *platon)
{
	if (!platon->eat && (get_time() > platon->what))
	{
		ft_putstr_fd("PHILO DEAD\n", 1);
		pthread_mutex_lock(&platon->data->write_mutex);
		pthread_mutex_unlock(&platon->data->die_mutex);
		return (EXIT_ERROR);
	}
	return (EXIT_OK);
}

int	ft_take_forks(t_philo *arendt)
{
	int	i;
	int	chopstick;

	i = 0;
	while (i < 2)
	{
		if (ft_is_dead(arendt))
			return (EXIT_ERROR);
		if (i == 0)
			chopstick = arendt->left_chpstck;
		else
			chopstick = arendt->right_chpstck;
		pthread_mutex_lock(&arendt->data->chop_mutex[chopstick]);
	}
}

void	ft_habit(void *socrate)
{
	t_philo *kant;

	kant = (t_philo *)socrate;
	kant->last_meal = get_time();
	while (1)
	{
		//faut manger prendre les fouchettes et dormir ici ?
		if (ft_take_forks(kant))
			break;
	}
}

int	ft_routine(t_data *data)
{
	int	i;
	pthread_t	thread;

	i = 0;
	pthread_mutex_lock(&data->die_mutex);
	while (i < data->num_philo)
	{
		pthread_create(&thread, NULL, &ft_habit, &data->rousseau[i]);
		if (!thread)
			ft_putstr_fd("Errorrr a pthread_create dans ft_routine\n", 2);
		pthread_detach(thread);
		i++;
	}
	return (EXIT_OK);
}