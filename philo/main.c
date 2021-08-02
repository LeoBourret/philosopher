/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:38:42 by lebourre          #+#    #+#             */
/*   Updated: 2021/08/02 13:23:44 by lebourre         ###   ########.fr       */
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

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	pthread_mutex_lock(philo->mutex);
	while (1)
	{
		
	}
	return (philo);
}

static int	start_thread(t_settings *set)
{
	int				i;
	pthread_mutex_t	mutex;
	pthread_t		tid;

	pthread_mutex_init(&mutex, NULL);
	set->start = get_time();
	i = -1;
	while (++i < set->philo_nb)
	{
		printf("init thread %d\n", i);
		set->philos[i].mutex = &mutex;
		printf("mutex given\n");
		pthread_create(&tid, NULL, routine, (void *)&set->philos[i]);
		printf("thread %d done\n", i);
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
