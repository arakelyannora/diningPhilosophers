/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nora <nora@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:42:18 by nora              #+#    #+#             */
/*   Updated: 2021/10/11 21:42:21 by nora             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	start(t_params *param, int argc, char **argv)
{
	if (init(param, argc, argv) == FAIL)
		return (FAIL);
	return (SUCCESS);
}