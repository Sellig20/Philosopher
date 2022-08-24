/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannecolmou <jeannecolmou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:00:27 by jecolmou          #+#    #+#             */
/*   Updated: 2022/08/24 19:34:41 by jeannecolmo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*usleep dans one philo pour le temps de die parce quici ca fait direct parce que c du code brut. pthread create, usleep, msg mort, parce que il a jamais trouver de deuxieme fourchette parce quil est tout seul. usleep tdeath. 

Attention aux deadlock et faux dead lock (warning sur fsanitize mais ca defend en crrection puisque ca marche) :
 si tu lock puis unlock il faut que ce soit dans l'ordre or vu que ce sont des philos en cercle forcement le 1er et dernier ne se touchent pas en numero.
une datarace c'est quand tout le monde se rue sur 1 variable en meme temps d'ou le pq il faut lock une variable.
tu lockes la variable dead quand elle se remplit dun mort pour pas quils la crashent tous en meme tmps.*/

#include "../philosopher.h"

int ft_check_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->die_mutex);
	//printf("%ld\n", philo->last_meal - philo->data->time_start);
	if (philo->data->status == 1)
	{
		pthread_mutex_unlock(&philo->data->die_mutex);
		return (-1);
	}
	if ((ft_get_time() - philo->last_meal) > philo->data->tdeath)
	{
		printf("%ld %d has died", (ft_get_time() - philo->data->time_start), philo->index);
		philo->data->status = 1;
		pthread_mutex_unlock(&philo->data->die_mutex);
		return (-1);
	}
	if (philo->data->status == 0)
	{
		pthread_mutex_unlock(&philo->data->die_mutex);
		return (0);
	}
	return (0);
}

void	*ft_habit(void *socrate)
{
	t_philo *kant;
	kant = (t_philo *)socrate;
	if (kant->index % 2)
		usleep(15 * 1000); //usleep est en nanosecnode donc * 1000 pour convertir en milili
	while (1)
	{
		if (ft_check_status(kant) != 0)
			return (NULL);
		ft_is_eating(kant);
		if (ft_check_status(kant) != 0)
			return (NULL);
		ft_is_sleeping(kant);
		if (ft_check_status(kant) != 0)
			return (NULL);
		ft_is_thinking(kant);
		if (ft_check_status(kant) != 0)
			return (NULL);
	}
}
