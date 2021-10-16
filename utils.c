/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nora <nora@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 09:14:17 by nora              #+#    #+#             */
/*   Updated: 2021/10/16 09:15:50 by nora             ###   ########.fr       */
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