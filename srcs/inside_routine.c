/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:24:20 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/26 16:31:11 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_is_dead(t_philo *platon)
{
	if (!platon->eat && (ft_get_time() > platon->what))
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
	return (EXIT_OK);
}
