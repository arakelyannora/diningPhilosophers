/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nora <nora@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:03:10 by nora              #+#    #+#             */
/*   Updated: 2021/10/09 10:21:11 by nora             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s)
	{
		length++;
		s++;
	}
	return (length);
}

int	string_to_int(char *str)
{
	int	num;

	num = 0;
	if (ft_strlen(str) > 10)
		return (-1);
	while (*str)
	{
		if (!(ft_isdigit(*str)) || (num == 214748364 && (*str) - 48 > 7))
			return (-1);
		num = num * 10 + ((*str) - 48);
		str++;
	}
	return (num);
}

void	init(t_params *param, int argc, char **argv)
{
	param->number_of_philos = string_to_int(argv[1]);
	param->time_to_die = string_to_int(argv[2]);
	param->time_to_eat = string_to_int(argv[3]);
	param->time_to_sleep = string_to_int(argv[4]);
	if (argc == 6)
	{
		param->number_of_times_to_eat = string_to_int(argv[5]);
	}
	else
	{
		param->number_of_times_to_eat = -1;
	}
}
