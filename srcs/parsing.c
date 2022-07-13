/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:22:11 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/13 18:09:24 by jecolmou         ###   ########.fr       */
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

int	ft_check_digit(char	**argv, int i)
{
	int j = 0;
	i++;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
				return (ft_putstr_fd("Error\n", 2), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_parse(int argc, char **argv, int i)
{
	if (ft_check_digit(argv, i) == 0)
		return (1);
	if (ft_check_args(argc, argv) == 0)
		return (1);
	return (0);
}
