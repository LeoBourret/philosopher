/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:56:27 by lebourre          #+#    #+#             */
/*   Updated: 2021/08/05 23:30:34 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philo(t_settings *settings)
{
	int	i;

	i = -1;
	pthread_mutex_init(&settings->philos[0].m_msg, NULL);
	while (++i < settings->philo_nb)
	{
		settings->philos[i].position = i;
		settings->philos[i].status = 0;
		settings->philos[i].meal_count = 0;
		settings->philos[i].m_msg = settings->philos[0].m_msg;
		pthread_mutex_init(&settings->philos[i].mutex, NULL);
		pthread_mutex_init(&settings->philos[i].l_fork, NULL);
		if (i != 0)
			settings->philos[i].r_fork = &settings->philos[i - 1].l_fork;
		settings->philos[i].settings = settings;
	}
	settings->philos[0].r_fork = &settings->philos[i - 1].l_fork;
}

t_settings	*set_settings(int ac, char **av)
{
	t_settings *settings;

	(void)ac;
	settings = malloc(sizeof(t_settings));
	if (settings == NULL)
		return (NULL);
	settings->philo_nb = ft_atoi(av[0]);
	settings->time_to_die = ft_atoi(av[1]);
	settings->time_to_eat = ft_atoi(av[2]);
	settings->time_to_sleep = ft_atoi(av[3]);
	if (ac == 6)
		settings->meal_to_win = ft_atoi(av[4]);
	settings->philos = malloc(sizeof(t_philo) * (settings->philo_nb));
	if (settings->philos == NULL)
		return (NULL);
	set_philo(settings);
	return (settings);
}
