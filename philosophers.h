/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nora <nora@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:06:07 by nora              #+#    #+#             */
/*   Updated: 2021/10/16 11:38:58 by nora             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define SUCCESS 0
# define FAIL    1
# define WRONG_PARAMS_NUMBER 2
# define MUTEX_INIT_FAIL	 3
# define MUTEX_DESTROY_FAIL 5
# define NEG_PARAM	-1
# define MALLOC_ERROR 4
# define SLEEP 10
# define HUNGRY 11
# define THINKING 12
# define EATING 13
# define GETTIME 14

typedef struct timeval	t_time;

typedef struct s_philo
{	
	int			left_fork;
	int			right_fork;
	int			tot_meals;
	int			state;
	t_time		last_meal;
	t_time		start;
	pthread_t	*thread;
}	t_philo;

typedef struct s_params
{
	int			num_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			tot_meals_num;
}	t_params;

typedef struct s_info
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*common_mutex;
	t_params		params;
}	t_info;

int		errors(int error_number);
int		init(t_info *info, t_philo *philos, int argc, char **argv);
int		start(t_info *info, int argc, char **argv);
int		t_isdigit(int arg);
size_t	ft_strlen(const char *s);
int		string_to_int(char *str);
void	free_(t_philo *philo, pthread_mutex_t *forks);
int		destroy_forks_mutexs(int n, t_info *info);
int		destroy_mutexs(t_info *info);

#endif