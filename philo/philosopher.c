/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannecolmou <jeannecolmou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:09:15 by jecolmou          #+#    #+#             */
/*   Updated: 2022/09/17 17:29:36 by jeannecolmo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    ft_exit(t_philo *philo, t_data *data)
{
    int i;

    i = data->num_philo;
    while (i > 0)
    {
        pthread_mutex_destroy(&philo->data->chop_mutex[i]);
        i--;
    }
    pthread_mutex_destroy(&philo->data->eat_mutex);
    pthread_mutex_destroy(&philo->data->die_mutex);
    pthread_mutex_destroy(&philo->data->message);
    free(data->tab_meal);
    free(data->chop_mutex);
    free(data);
    free(philo);
    return ;
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	int		i;

	i = 0;
	data = malloc(sizeof(t_data));
	ft_bzero(data, sizeof(data));
	if (ft_parse(argc, argv, i, data) == 0)
		return (1);
	if (!data)
		return (1);
	if (ft_settle_variables(argv, data) == 0)
		return (1);
	philo = malloc(sizeof(t_philo) * data->num_philo);
    if (!philo)
        return (free(data), 1);
	ft_init_philo(philo, data);
	if (ft_init_mutex(data) == 0)
		return (free(data), free (philo), ft_putstr_fd("Error mutex\n", 2), 1);
	ft_init_thread(philo);
	ft_exit(philo, data);
    return (0);
}