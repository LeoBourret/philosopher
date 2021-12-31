/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:41:29 by lebourre          #+#    #+#             */
/*   Updated: 2021/08/06 01:50:16 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_messages(philo, STATUS_FORK);
	pthread_mutex_lock(&philo->l_fork);
	print_messages(philo, STATUS_FORK);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_eat);
	philo->status = STATUS_EAT;
	philo->last_meal = get_exec_time(philo->settings->start);
	philo->death_timer = philo->last_meal + philo->settings->time_to_die;
	print_messages(philo, STATUS_EAT);
	usleep(philo->settings->time_to_eat * 1000);
	philo->meal_count++;
	if (philo->meal_count == philo->settings->meal_to_win)
		philo->settings->philos_win++;
	philo->status = STATUS_SLEEP;
	pthread_mutex_unlock(&philo->m_eat);
}

void	philo_sleep(t_philo *philo)
{
	print_messages(philo, STATUS_SLEEP);
	pthread_mutex_unlock(&philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	usleep(philo->settings->time_to_sleep * 1000);
}
