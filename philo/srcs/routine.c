/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:00:27 by jecolmou          #+#    #+#             */
/*   Updated: 2022/08/06 17:06:37 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Attention aux deadlock et faux dead lock (warning sur fsanitize mais ca defend en crrection puisque ca marche) :
 si tu lock puis unlock il faut que ce soit dans l'ordre or vu que ce sont des philos en cercle forcement le 1er et dernier ne se touchent pas en numero.
une datarace c'est quand tout le monde se rue sur 1 variable en meme temps d'ou le pq il faut lock une variable.
tu lockes la variable dead quand elle se remplit dun mort pour pas quils la crashent tous en meme tmps.*/

#include "../philosopher.h"

void	*ft_habit(void *socrate)
{
	t_philo *kant;
	kant = (t_philo *)socrate;
	if (kant->index % 2)
		usleep(15 * 1000); //usleep est en nanosecnode donc * 1000 pour convertir en milili
	while (1)
	{
		if (ft_take_chopsticks(kant) || ft_eat(kant) /*|| ft_chopstick_back(kant)*/)
		{
			break;
		}
	}
	return (NULL);
}

void	ft_routine(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_philo)
	{
		pthread_create(&philo[i].thread, NULL, ft_habit, &philo[i]);
		if (!philo[i].thread)
			ft_putstr_fd("Errorrr a pthread_create dans ft_routine\n", 2);
		i++;
	}
	i = 0;
	while (i < philo->data->num_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
