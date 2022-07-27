/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannecolmou <jeannecolmou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:24:20 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/27 16:46:53 by jeannecolmo      ###   ########.fr       */
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
	ft_putstr_fd("philo is eating\n", 1);
}

int	ft_take_chopsticks(t_philo *arendt)
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
		ft_putstr_fd("taking chopstick !\n", 1);
	}
	return (EXIT_OK);
}
