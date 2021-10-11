/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nora <nora@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:03:10 by nora              #+#    #+#             */
/*   Updated: 2021/10/11 21:40:58 by nora             ###   ########.fr       */
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
		return (NEG_PARAM);
	while (*str)
	{
		if (!(ft_isdigit(*str)) || (num == 214748364 && (*str) - 48 > 7))
			return (NEG_PARAM);
		num = num * 10 + ((*str) - 48);
		str++;
	}
	return (num);
}

int	init_thread_mutex(t_params *params)
{
	int	i;
	int	num;

	i = 0;
	num = params->num_of_philos;
	if (params->num_of_philos == 1)
		num = 2;
	while (i < num)
	{
		if (pthread_mutex_init(&params->mutexs->fork[i], NULL))
		{
			errors(MUTEX_INIT_FAIL);
			return (FAIL);
		}
	}
	while (i < params->num_of_philos)
	{
	}
}

int	init(t_params *param, int argc, char **argv)
{
	param->num_of_philos = string_to_int(argv[1]);
	param->time_to_die = string_to_int(argv[2]);
	param->time_to_eat = string_to_int(argv[3]);
	param->time_to_sleep = string_to_int(argv[4]);
	if (argc == 6)
	{
		param->tot_meals_num = string_to_int(argv[5]);
		if (param->tot_meals_num == NEG_PARAM)
		{
			errors(NEG_PARAM);
			return (FAIL);
		}
	}
	else
		param->tot_meals_num = -1;
	if (param->num_of_philos == NEG_PARAM || param->time_to_die == NEG_PARAM
		|| param->time_to_eat == NEG_PARAM || param->time_to_sleep == NEG_PARAM)
	{
		errors(NEG_PARAM);
		return (FAIL);
	}
	return (SUCCESS);
	//init_thread_mutex(param);
}
