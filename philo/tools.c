/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:14:26 by lebourre          #+#    #+#             */
/*   Updated: 2021/07/27 12:26:14 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	u_int64_t	result;

	i = 0;
	while (str[0] == '\t' || str[0] == '\n' || str[0] == '\v' ||
			str[0] == '\f' || str[0] == ' ' || str[0] == '\r')
		str++;
	result = 0;
	if (str[0] == '-')
		sign = -1;
	else
		sign = 1;
	if (str[0] == '+' || str[0] == '-')
		str++;
	while (str[0] == '0')
		str++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + (str[i++] - '0');
	if (i > 19 || result >= 9223372036854775808ULL)
		return (0);
	return (result * sign);
}

u_int64_t	get_exec_time(u_int64_t start)
{
	struct timeval tv;

	gettimeofday(&tv,(struct timezone *)0);
	return((tv.tv_sec * 1000LU + tv.tv_usec / 1000LU) - start);
}

u_int64_t	get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv,(struct timezone *)0);
	return(tv.tv_sec * 1000LU + tv.tv_usec / 1000LU);
}
