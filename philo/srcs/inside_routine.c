/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:24:20 by jecolmou          #+#    #+#             */
/*   Updated: 2022/08/05 17:35:01 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_is_dead(t_philo *platon)
{
	/*si a chaque gettime + tdeath il n'a pas mange*/
	if (platon->eat <= platon->data->tdeath)
	{
		pthread_mutex_lock(&platon->data->message);
		ft_putstr_fd("PHILO DEAD\n", 1);
		pthread_mutex_unlock(&platon->data->message);
		return (EXIT_ERROR);
	}
	return (EXIT_OK);
}

int	ft_eat(t_philo *aristote)
{
	aristote->eat++;
	pthread_mutex_lock(&aristote->data->message);
	printf("philo is eating\n");
	pthread_mutex_unlock(&aristote->data->message);
	return (EXIT_OK);
}

int	ft_take_chopsticks(t_philo *arendt)
{
	int	i;
	int	chopstick;
	i = 0;
	while (i < 2)
	{
		if (ft_is_dead(arendt) == 0)
			return (EXIT_ERROR);
		if (i == 0)
			chopstick = arendt->left_chpstck;
		else
			chopstick = arendt->right_chpstck;
		pthread_mutex_lock(&arendt->data->chop_mutex[chopstick]);
		pthread_mutex_lock(&arendt->data->message);
		printf("taking chopstick !\n");
		pthread_mutex_unlock(&arendt->data->message);
		pthread_mutex_unlock(&arendt->data->chop_mutex[chopstick]);
		i++;
	}
	return (EXIT_OK);
}
