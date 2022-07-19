/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:09:15 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/19 16:12:28 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_check_death(char	**argv, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i][j])
	{
		
	}
}

int main(int argc, char **argv)
{
	t_data	data;
	int	i;

	i = 0;
	ft_bzero(&data, sizeof(data));
	if (ft_parse(argc, argv, i, &data) == 0)
		return (1);
	printf("num philo = %d\n", data.num_philo);
	printf("num chops = %d\n", data.num_chopstick);



	return (0);
}

