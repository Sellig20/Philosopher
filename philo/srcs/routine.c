/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:00:27 by jecolmou          #+#    #+#             */
/*   Updated: 2022/08/06 19:09:30 by jecolmou         ###   ########.fr       */
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
		ft_is_eating(kant);
		ft_is_sleeping(kant);
		ft_is_thinking(kant);
	}
	return (NULL);
}
