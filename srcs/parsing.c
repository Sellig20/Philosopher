/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:22:11 by jecolmou          #+#    #+#             */
/*   Updated: 2022/09/08 10:01:08 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	(void)argc;
	if (ft_strlen(argv[i]) == 0)
		return (ft_putstr_fd("Error : empty argument\n", 2), 0);
	if (argv[i] == NULL)
		return (ft_putstr_fd("Error : empty argument\n", 2), 0);
	return (1);
}

int	ft_check_digit(char	**argv)
{
	int	j;
	int	k;

	j = 1;
	k = 0;
	while (argv[j])
	{
		while (argv[j][k])
		{
			if (argv[j][0] == '-')
				return (ft_putstr_fd("Error : negative number\n", 2), 0);
			if (!(argv[j][k] >= '0' && argv[j][k] <= '9'))
				return (ft_putstr_fd("Error : not only num in args \n", 2), 0);
			k++;
		}
		j++;
	}
	return (1);
}

int	ft_one_philo(t_data *data)
{
	printf("%ld %d has taken a fork\n", (data->tdeath), 1);
	printf("%ld %d is dead\n", (data->tdeath + 1), 1);
	return (0);
}

int	ft_get_num_philo(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[1]) == 1)
			return (ft_one_philo(data), 0);
		if (ft_atoi(argv[1]) <= 0)
			return (ft_putstr_fd("Error : no philosophers\n", 2), 0);
		else if (ft_atoi(argv[1]) > 200)
			return (ft_putstr_fd("Error : too many philosophers\n", 2), 0);
		else if (ft_strlen(argv[i]) == 0)
			return (ft_putstr_fd("Error : empty args\n", 2), 0);
		else if (ft_atol(argv[i]) > INT_MAX)
			return (ft_putstr_fd("Error : limit int reached\n", 2), 0);
		i++;
	}
	data->num_philo = ft_atoi(argv[1]);
	data->num_chopstick = data->num_philo;
	return (1);
}

int	ft_parse(int argc, char **argv, int i, t_data *data)
{
	i = 1;
	while (i < argc)
	{
		if (ft_check_digit(argv) == 0)
			return (0);
		i++;
	}
	if (ft_check_args(argc, argv) == 0)
		return (0);
	if (ft_get_num_philo(argv, data) == 0)
		return (0);
	return (1);
}
