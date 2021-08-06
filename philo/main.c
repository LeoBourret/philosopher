/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:38:42 by lebourre          #+#    #+#             */
/*   Updated: 2021/08/06 01:20:36 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char **av)
{
	u_int64_t	value;

	while (*av)
	{
		value = ft_atoi(*av);
		if (value == 0)
			return (1);
		av++;
	}
	return (0);
}

void	*philo_checker(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (philo->status != STATUS_EAT && get_exec_time(philo->settings->start)
			> philo->death_timer)
		{
			print_messages(philo, STATUS_DEAD);
			return ((void *)0);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
}

void	*routine(void *philo_ptr)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)philo_ptr;
	philo->last_meal = get_exec_time(philo->settings->start);
	philo->death_timer = philo->last_meal + philo->settings->time_to_die;
	if ((pthread_create(&tid, NULL, philo_checker, philo_ptr)) != 0)
		return ((void *)1);
	pthread_detach(tid);
	while (1)
	{
		take_fork(philo);
		eat(philo);
		philo_sleep(philo);
		print_messages(philo, STATUS_THINK);
	}
	return ((void *)0);
}

static int	start_thread(t_settings *set)
{
	int				i;
	pthread_t		tid;

	set->start = get_time();
	i = -1;
	while (++i < set->philo_nb)
	{
		if ((pthread_create(&tid, NULL, routine, (void *)&set->philos[i])) != 0)
			return (1);
		pthread_detach(tid);
		usleep(100);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_settings	*set;

	if (ac < 5 || ac > 6 || check_arg(av + 1))
		return (exit_error(BAD_ARGUMENT));
	set = set_settings(ac, av + 1);
	if (!set)
		return (exit_error(MALLOC_ERROR));
	start_thread(set);
	return (0);
}
