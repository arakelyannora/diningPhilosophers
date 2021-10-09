/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nora <nora@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:02:54 by nora              #+#    #+#             */
/*   Updated: 2021/10/09 10:09:09 by nora             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_params *param)
{
	printf("number_of_philos %d\n", param->number_of_philos);
	printf("time_to_die %d\n", param->time_to_die);
	printf("time_to_eat %d\n", param->time_to_eat);
	printf("time_to_sleep %d\n", param->time_to_sleep);
	printf("number_of_times_each_philo_must_eat %d\n",
		param->number_of_times_to_eat);
}

int	main(int argc, char **argv)
{
	t_params	param;

	if (argc == 5 || argc == 6)
	{
		init(&param, argc, argv);
		print(&param);
	}
	else
	{
		errors(WRONG_PARAMS_NUMBER);
	}
	return (0);
}
