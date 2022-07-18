/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeannecolmou <jeannecolmou@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:22:11 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/18 15:27:05 by jeannecolmo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5)
		return (ft_putstr_fd("Error : number of argument\n", 2), 0);
	if (ft_strlen(argv[i]) == 0)
		return (ft_putstr_fd("Error : empty argument\n", 2), 0);
	if (argv[i] == NULL)
		return (ft_putstr_fd("Error : empty argument\n", 2), 0);
	return (1);
}

int	ft_isdigit(int c)
{
	while (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_check_digit(int argc, char	**argv, int i)
{
	int j;
	i = 1;
	(void)argc;
	// while (i < argc)
	// {
	
		j = 1;
		while (argv[j])
		{
			int k = 0;
			while (argv[j][k])
			{
				if (!(argv[j][k] >= '0' && argv[j][k] <= '9'))
					return (ft_putstr_fd("Error : not only numbers in the arguments \n", 2), 0);
				k++;
			}
			j++;
		}
		// while (argv[j])
		// {
		// 		printf("oui\n");
		// 		printf("dd = %d\n", ft_atoi(argv[j]));
		// 		if (!(ft_atoi(argv[j]) >= 1 && ft_atoi(argv[j]) <= 9))
		// 			return (ft_putstr_fd("Errorrr\n", 2), 0);
		// 	j++;
		// }
		// i++;
	//}
	return (1);
}

int	ft_get_num_philo(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == '1')
		{
			ft_putstr_fd("1 philo = death\n", 2);
			return (0);
		}
		else
			data->num_philo = ft_atoi(argv[i]);
		i++;
	}
	return (1);
}

int	ft_parse(int argc, char **argv, int i, t_data *data)
{
	i = 1;
	while (i < argc)
	{
		if (ft_check_digit(argc, argv, i) == 0)
			return (0);
		i++;
	}
	if (ft_check_args(argc, argv) == 0)
		return (0);
	if (ft_get_num_philo(&argv[1], data) == 0)
		return (0);
	return (1);
}
