/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:43:31 by lebourre          #+#    #+#             */
/*   Updated: 2021/08/06 01:13:30 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_and_lock_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_dead);
	philo->settings->status = STATUS_DEAD;
	printf("%llu\t%d died.\n",
		get_exec_time(philo->settings->start), philo->position + 1);
	usleep(20000);
	pthread_mutex_unlock(&philo->m_dead);
}

void	print_messages(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->m_msg);
	if (philo->settings->status != STATUS_DEAD)
	{
		if (status == STATUS_THINK)
			printf("%llu\t%d is thinking.\n",
				get_exec_time(philo->settings->start), philo->position + 1);
		else if (status == STATUS_EAT)
			printf("%llu\t%d is eating.\n",
				get_exec_time(philo->settings->start), philo->position + 1);
		else if (status == STATUS_FORK)
			printf("%llu\t%d has taken a fork.\n",
				get_exec_time(philo->settings->start), philo->position + 1);
		else if (status == STATUS_DEAD)
			print_and_lock_death(philo);
		else if (status == STATUS_SLEEP)
			printf("%llu\t%d is sleeping.\n",
				get_exec_time(philo->settings->start), philo->position + 1);
	}
	pthread_mutex_unlock(&philo->m_msg);
}
