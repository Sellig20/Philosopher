/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannecolmou <jeannecolmou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:22:11 by jecolmou          #+#    #+#             */
/*   Updated: 2022/09/17 17:29:39 by jeannecolmo      ###   ########.fr       */
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
		if (ft_atoi(argv[1]) == 0)
			return (ft_putstr_fd("Error : no philosophers\n", 2), 0);
		if (!ft_isnum(argv[j]))
			return (ft_putstr_fd("Error : not only num in args \n", 2), 0);
		if (ft_atoi(argv[j]) == 0)
			return (ft_putstr_fd("Error : number is 0\n", 2), 0);
		while (argv[j][k])
		{
			if (argv[j][0] == '-')
				return (ft_putstr_fd("Error : negative number\n", 2), 0);
			k++;
		}
		j++;
	}
	return (1);
}

int	ft_one_philo(char **argv)
{
	printf("%d %d has taken a fork\n", 0, 1);
	usleep(ft_atoi(argv[2]) * 1000);
	printf("%d %d is dead\n", (ft_atoi(argv[2]) + 1), 1);
	return (0);
}

int	ft_get_num_philo(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[1]) == 1)
			return (ft_one_philo(argv), 0);
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
