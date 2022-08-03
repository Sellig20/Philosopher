/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:00:27 by jecolmou          #+#    #+#             */
/*   Updated: 2022/08/03 17:38:35 by jecolmou         ###   ########.fr       */
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

	printf("debug 1\n");
	kant = (t_philo *)socrate;
	kant->last_meal = ft_get_time();
	while (1)
	{
		//faut manger prendre les fouchettes et dormir ici ?
		// if (ft_eat(kant))
		// 	break;
		if (ft_take_chopsticks(kant) || ft_eat(kant) /*|| ft_chopstick_back(kant)*/)
			break;
	}
	return (NULL);
}

int	ft_routine(t_data *data)
{
	int	i;
	pthread_t	thread;

	i = 0;
	pthread_mutex_lock(&data->die_mutex);
	while (i < data->num_philo)
	{
		pthread_create(&thread, NULL, ft_habit, &data->rousseau[i]);
		printf("OUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n");
		if (!thread)
			ft_putstr_fd("Errorrr a pthread_create dans ft_routine\n", 2);
		pthread_detach(thread);
		i++;
	}
	return (EXIT_OK);
}
