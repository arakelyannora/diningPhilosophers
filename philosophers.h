/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nora <nora@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:06:07 by nora              #+#    #+#             */
/*   Updated: 2021/10/11 21:40:19 by nora             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <pthread.h>

# define SUCCESS 0
# define FAIL    1
# define WRONG_PARAMS_NUMBER 2
# define MUTEX_INIT_FAIL	 3
# define NEG_PARAM	-1

typedef struct s_philos
{
	pthread_mutex_t	*fork;
	pthread_t		*philosopher;
}	t_philos;

typedef struct s_params
{
	t_philos	*mutexs;
	int			num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			tot_meals_num;
}	t_params;

void	errors(int error_number);
int		init(t_params *param, int argc, char **argv);
int		start(t_params *param, int argc, char **argv);

#endif