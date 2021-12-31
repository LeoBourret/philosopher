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
#include <sys/types.h>

unsigned int	ft_strlen(const char *s)
{
	unsigned int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

u_int64_t	ft_atoi(const char *str)
{
	int			i;
	u_int64_t	result;

	i = 0;
	while (str[0] == '\t' || str[0] == '\n' || str[0] == '\v' ||
			str[0] == '\f' || str[0] == ' ' || str[0] == '\r')
		str++;
	result = 0;
	if (str[0] == '+' || str[0] == '-')
		str++;
	while (str[0] == '0')
		str++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + (str[i++] - '0');
	return (result);
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

void	ft_usleep(u_int64_t ms_time)
{
	int	exect_time;

	exect_time = get_time();
	while ((get_time() - exect_time) < ms_time)
		usleep(ms_time / 10);
}
