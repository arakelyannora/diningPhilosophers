/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nora <nora@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:03:10 by nora              #+#    #+#             */
/*   Updated: 2021/10/16 11:51:58 by nora             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philosophers(t_info *info, t_time time)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < info->params.num_of_philos)
	{
		philo = &(info->philos[i]);
		philo->left_fork = i;
		philo->right_fork = (i + 1) % info->params.num_of_philos;
		philo->state = THINKING;
		philo->start = time;
		philo->last_meal = time;
		philo->tot_meals = 0;
		i++;
	}
}

int	init_mutexs(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->params.num_of_philos)
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL))
		{
			return (destroy_forks_mutexs(i, info));
			return (MUTEX_INIT_FAIL);
		}
		i++;
	}
	if (pthread_mutex_init(info->common_mutex, NULL))
	{
		return (MUTEX_INIT_FAIL);
	}
	return (SUCCESS);
}

int	continue_init(t_info *info, t_philo *philos)
{
	int		i;
	int		res;
	t_time	time;

	i = 0;
	res = SUCCESS;
	if (gettimeofday(&time, NULL))
		return (GETTIME);
	philos = malloc(sizeof(t_philo) * info->params.num_of_philos);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->params.num_of_philos);
	info->philos = philos;
	if (!philos || !info->forks)
	{
		free_(philos, info->forks);
		return (error(MALLOC_ERROR));
	}
	init_philosophers(info, time);
	res = init_mutexs(info);
	if (res)
		errors(res);
	free(philos);
	free(info->forks);
	return (res);
}

int	init(t_info *info, t_philo *philos, int argc, char **argv)
{
	info->params.num_of_philos = string_to_int(argv[1]);
	info->params.time_to_die = string_to_int(argv[2]);
	info->params.time_to_eat = string_to_int(argv[3]);
	info->params.time_to_sleep = string_to_int(argv[4]);
	info->params.tot_meals_num = -1;
	if (argc == 6)
	{
		info->params.tot_meals_num = string_to_int(argv[5]);
		if (info->params.tot_meals_num == NEG_PARAM)
		{
			return (errors(NEG_PARAM));
		}
	}
	if (info->params.num_of_philos == NEG_PARAM
		|| info->params.time_to_die == NEG_PARAM
		|| info->params.time_to_eat == NEG_PARAM
		|| info->params.time_to_sleep == NEG_PARAM)
	{
		return (errors(NEG_PARAM));
	}
	return (continue_init(info, philos));
}
