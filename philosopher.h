/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:39:51 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/13 16:44:52 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

//////////STRUCTURE/////////
typedef struct s_data		t_data;

struct s_data
{
	int	phil;
	int	death;
	int	eat;
	int	sleep;
};

//////////PARSING//////////
int	ft_check_digit();

#endif
