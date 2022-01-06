/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:08:28 by lebourre          #+#    #+#             */
/*   Updated: 2021/07/26 15:07:03 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_philo(t_settings *set)
{
	int i;

	i = -1;
	pthread_mutex_destroy(&set->philos[0].m_msg);
	pthread_mutex_destroy(&set->philos[0].m_dead);
	while (++i < set->philo_nb)
		pthread_mutex_destroy(&set->philos[i].l_fork);
	free(set->philos);
	free(set);
}

int	exit_error(char *s)
{
	printf("%s\n", s);
	return (0);
}
