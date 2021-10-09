/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nora <nora@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 23:29:31 by nora              #+#    #+#             */
/*   Updated: 2021/10/09 10:06:45 by nora             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	errors(int error_number)
{
	if (error_number == 0)
	{
		printf("Wrong number of parameters\n");
	}
	printf("Usage: ./philosophers number_of_philos time_to_die\
    time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat\n");
}
