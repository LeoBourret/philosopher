/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:38:42 by lebourre          #+#    #+#             */
/*   Updated: 2021/07/06 20:13:04 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char **av)
{
	u_int64_t	value;

	while (*av)
	{
		value = ft_atoi(*av);
		if (value == 0 || value == -1)
			return (1);
		av++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_settings *settings;

	if (ac < 5 || ac > 6 || check_arg(av + 1))
		return (exit_error(BAD_ARGUMENT));
	settings = set_settings(ac, av + 1);
	if (!settings)
		return (exit_error(MALLOC_ERROR));
}
