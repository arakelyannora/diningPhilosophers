/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nora <nora@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:42:18 by nora              #+#    #+#             */
/*   Updated: 2021/10/16 11:37:39 by nora             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	start(t_info *info, int argc, char **argv)
{
	t_philo	philos;

	return (init(info, &philos, argc, argv));
}
