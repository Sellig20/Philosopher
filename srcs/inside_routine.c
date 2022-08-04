/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:24:20 by jecolmou          #+#    #+#             */
/*   Updated: 2022/08/04 22:27:10 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_is_dead(t_philo *platon)
{
	/*si a chaque gettime + tdeath il n'a pas mange*/
	if (platon->eat <= platon->data->tdeath)
	{
		ft_putstr_fd("PHILO DEAD\n", 1);
		pthread_mutex_lock(&platon->data->write_mutex);
		pthread_mutex_unlock(&platon->data->die_mutex);
		return (EXIT_ERROR);
	}
	return (EXIT_OK);
}

int	ft_eat(t_philo *aristote)
{
	aristote->eat++;
	printf("philo is eating\n");
	return (EXIT_OK);
}

int	ft_take_chopsticks(t_philo *arendt)
{
	int	i;
	int	chopstick;
	printf("JE SUIS DANS TAKE CHOPSTICK\n");
	i = 0;
	while (i < 2)
	{
		printf("JE SUIS DANS WHILE DE TAKE CHOP\n");
		if (ft_is_dead(arendt) == 0)
			return (EXIT_ERROR);
		if (i == 0)
			chopstick = arendt->left_chpstck;
		else
			chopstick = arendt->right_chpstck;
		pthread_mutex_lock(&arendt->data->chop_mutex[chopstick]);
		//printf(" temps = %ld", ft_get_time());
		printf("taking chopstick !\n");
		pthread_mutex_unlock(&arendt->data->chop_mutex[chopstick]);
		i++;
	}
	return (EXIT_OK);
}

// int ft_chopstick_back(t_philo *nietzsche)
// {

// }
