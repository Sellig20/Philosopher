/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:28:57 by jecolmou          #+#    #+#             */
/*   Updated: 2022/07/26 16:29:22 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

long ft_get_time(void)
{
	struct timeval  tv;
	gettimeofday(&tv, NULL);

	long time_in_mill =
			(tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;
	return (time_in_mill);
}
