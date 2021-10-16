/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nora <nora@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:27:30 by nora              #+#    #+#             */
/*   Updated: 2021/10/16 11:29:22 by nora             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_(t_philo *philo, pthread_mutex_t *forks)
{
	if (philo)
	{
		free(philo);
	}
	if (forks)
	{
		free(philo);
	}
}

int	destroy_forks_mutexs(int n, t_info *info)
{
	int	i;
	int	ret;

	i = 0;
	ret = MUTEX_INIT_FAIL;
	while (i < n)
	{
		ret += pthread_mutex_destroy(&(info->philos[i]));
		i++;
	}
	return (ret);
}

int	destroy_mutexs(t_info *info)
{
	int	ret;

	ret = MUTEX_INIT_FAIL;
	ret = destroy_forks_mutexs(info->params.num_of_philos, info->forks);
	ret = pthread_mutex_destroy(info->common_mutex);
	return (ret);
}