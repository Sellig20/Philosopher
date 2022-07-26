/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannecolmou <jeannecolmou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:22:11 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/23 02:10:24 by jeannecolmo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 6)
		return (ft_putstr_fd("Error : number of argument\n", 2), 0);
	if (ft_strlen(argv[i]) == 0)
		return (ft_putstr_fd("Error : empty argument\n", 2), 0);
	if (argv[i] == NULL)
		return (ft_putstr_fd("Error : empty argument\n", 2), 0);
	return (1);
}

int	ft_check_digit(char	**argv)
{
	int j;
	j = 1;
	while (argv[j])
	{
		int k = 0;
		while (argv[j][k])
		{
			if (argv[j][0] == '-')
				return (ft_putstr_fd("Error : negative number\n", 2), 0);
			if (!(argv[j][k] >= '0' && argv[j][k] <= '9'))
				return (ft_putstr_fd("Error : not only numbers in the arguments \n", 2), 0);
			k++;
		}
		j++;
	}
	return (1);
}

int	ft_get_num_philo(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[1]) == 1)
			return (ft_putstr_fd("1 philo = death\n", 2), 0);
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
