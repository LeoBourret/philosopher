/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:14:26 by lebourre          #+#    #+#             */
/*   Updated: 2021/07/06 18:52:44 by lebourre         ###   ########.fr       */
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
	sign = (str[0] == '-' ? -1 : 1);
	str = (str[0] == '-' || str[0] == '+') ? str + 1 : str;
	while (str[0] == '0')
		str++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
		result = result * 10 + (str[i++] - '0');
	if (i > 19 || result >= 9223372036854775808ULL)
		return (0);
	return (result * sign);
}
