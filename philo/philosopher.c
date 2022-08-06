/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:09:15 by jecolmou          #+#    #+#             */
/*   Updated: 2022/08/06 19:22:46 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// int	ft_check_death(char	**argv, t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (argv[i][j])
// 	{

// 	}
// }


// int	ft_un_alloc(t_data *data)
// {
// 	if ()
// }


int main(int argc, char **argv)
{
	t_data	*data;
	t_philo *philo;
	int	i;

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
	ft_init_philo(philo, data);
	if (ft_init_mutex(data) == 0)
		return (ft_putstr_fd("Error de init mutex\n", 2), 1);
	ft_init_thread(philo);




	return (0);
}
