/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:22:11 by jecolmou          #+#    #+#             */
/*   Updated: 2022/10/04 14:52:32 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	(void)argc;
	if (argv[i] == NULL)
		return (ft_putstr_fd("Error : Empty argument\n", 2), 0);
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
			return (ft_putstr_fd("Error : No philosophers\n", 2), 0);
		if (!ft_isnum(argv[j]))
			return (ft_putstr_fd("Error : Invalid arguments \n", 2), 0);
		if (ft_strlen(argv[j]) == 0)
			return (ft_putstr_fd("Error : Empty argument\n", 2), 0);
		if (ft_atoi(argv[j]) == 0)
			return (ft_putstr_fd("Error : No launch when num is 0\n", 2), 0);
		while (argv[j][k])
		{
			if (argv[j][0] == '-')
				return (ft_putstr_fd("Error : Negative number\n", 2), 0);
			k++;
		}
		j++;
	}
	return (1);
}

// int	ft_one_philo(char **argv)
// {
// 	printf("%d %d has taken a fork\n", 0, 1);
// 	usleep(ft_atoi(argv[2]) * 1000);
// 	printf("%d %d has died\n", (ft_atoi(argv[2]) + 1), 1);
// 	return (0);
// }

int	ft_get_num_philo(char **argv, t_data *data)
{
	int	i;

	i = 0;
	(void)data;
	while (argv[i])
	{
		// if (ft_atoi(argv[1]) == 1)
		// 	return (ft_one_philo(argv), 0);
		if (ft_atoi(argv[1]) <= 0)
			return (ft_putstr_fd("Error : No philosophers\n", 2), 0);
		else if (ft_atoi(argv[1]) > 200)
			return (ft_putstr_fd("Error : Too many philosophers\n", 2), 0);
		else if (ft_strlen(argv[i]) == 0)
			return (ft_putstr_fd("Error : Empty args\n", 2), 0);
		i++;
	}
	return (1);
}

int	ft_parse(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	if (argc < 5)
		return (ft_putstr_fd("Error : Missing arguments", 2), 0);
	if (ft_check_args(argc, argv) == 0)
		return (0);
	while (i < argc)
	{
		if (ft_check_digit(argv) == 0)
			return (0);
		i++;
	}
	if (ft_get_num_philo(argv, data) == 0)
		return (0);
	return (1);
}
