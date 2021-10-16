/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nora <nora@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 23:29:31 by nora              #+#    #+#             */
/*   Updated: 2021/10/16 11:32:16 by nora             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	errors(int error_number)
{
	if (error_number == WRONG_PARAMS_NUMBER)
	{
		printf("Wrong number of parameters\n");
		printf("Usage: ./philosophers number_of_philos time_to_die\
		time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat\n");
	}
	else if (error_number == MUTEX_INIT_FAIL)
		printf("Mutex initialization has failed\n");
	else if (error_number == NEG_PARAM)
		printf("Parameters can't be negative numbers\n");
	else if (error_number == MALLOC_ERROR)
		printf("Malloc error\n");
	else if (error_number == MUTEX_DESTROY_FAIL)
		print("Failed to destroy mutex\n");
}