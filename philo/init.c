/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 18:56:27 by lebourre          #+#    #+#             */
/*   Updated: 2021/07/27 12:06:10 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philo(t_settings *settings)
{
	int	i;

	i = -1;
	while (++i < settings->philo_nb)
	{
		settings->philos[i].position = i;
		settings->philos[i].last_meal = 0;
		settings->philos[i].status = 0;
		settings->philos[i].r_fork = 1;
		settings->philos[i].l_fork = 1;
	}
}

t_settings	*set_settings(int ac, char **av)
{
	t_settings *settings;

	settings = malloc(sizeof(t_settings));
	if (settings == NULL)
		return (NULL);
	settings->philo_nb = ft_atoi(av[0]);
	settings->time_to_die = ft_atoi(av[1]);
	settings->time_to_eat = ft_atoi(av[2]);
	settings->time_to_sleep = ft_atoi(av[3]);
	settings->meal_to_win = ft_atoi(av[4]);
	settings->philos = malloc(sizeof(t_philo) * (settings->philo_nb));
	if (settings->philos == NULL)
		return (NULL);
	return (settings);
}
