
int	ft_fork(t_philo *philo)
{
	int	i;
	int	fork;

	i = 0;
	while (i < 2)
	{
		if (i == 0)
			fork = philo->lf;
		else
			fork = philo->rf;
		pthread_mutex_lock(&philo->data->forks[fork]);
		ft_msg(philo, 1);
		i++;
	}
	return (0);
}

void	ft_eat(t_philo *philo)
{
	ft_fork(philo);
	pthread_mutex_lock(&philo->data->eat_mutex);
	philo->last_meal = ft_time();

	ft_msg(philo, 2);

	philo->data->meals[philo->id - 1]++;
	pthread_mutex_lock(&philo->data->stop_mutex);
	ft_stop(philo);
	pthread_mutex_unlock(&philo->data->stop_mutex);
	pthread_mutex_unlock(&philo->data->eat_mutex);
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->lf]);
	pthread_mutex_unlock(&philo->data->forks[philo->rf]);
}

void	ft_sleep(t_philo *philo)
{
	ft_msg(philo, 3);
	usleep(philo->data->time_sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	ft_msg(philo, 4);
	if (philo->data->time_eat * 2 > philo->data->time_die)
		usleep(((philo->data->time_die + 1) - (philo->data->time_eat
					+ philo->data->time_sleep)) * 1000);
}

void	ft_stop(t_philo *philo)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	if (philo->data->nb_eat >= 0)
	{
		while (philo->data->meals[index] >= philo->data->nb_eat)
		{
			if (i == philo->data->nb_philo - 1)
			{
				philo->data->status = 1;
				return ;
			}
			i++;
			index++;
		}
	}
}

void	ft_msg(t_philo *philo, int action)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	if (action == 1)
		printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id,
			FORK);
	else if (action == 2)
		printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id,
			EAT);
	else if (action == 3)
		printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id,
			SLEEP);
	else if (action == 4)
		printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id,
			THINK);
	else if (action == 5)
		printf("%ld %d %s", (ft_time() - philo->data->time_start), philo->id,
			DEAD);
	pthread_mutex_unlock(&philo->data->write_mutex);
	return ;
}

int	check_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->stop_mutex);
	if (philo->data->status == 1)
	{
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return (-1);
	}
	if ((ft_time() - philo->last_meal) > philo->data->time_die)
	{
		philo->data->status = 2;
	}
	if (philo->data->status == 0)
	{
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return (0);
	}
	else if (philo->data->status == 2)
	{
		ft_msg(philo, 5);
		philo->data->status = 1;
		pthread_mutex_unlock(&philo->data->stop_mutex);
		return (-1);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(15 * 1000);
	routine_loop(philo);
	return (NULL);
}

void	*routine_loop(t_philo *philo)
{
	while (1)
	{
		if (check_status(philo) != 0)
			return (NULL);
		ft_eat(philo);
		if (check_status(philo) != 0)
			return (NULL);
		ft_sleep(philo);
		if (check_status(philo) != 0)
			return (NULL);
		ft_think(philo);
		if (check_status(philo) != 0)
			return (NULL);
	}
}
