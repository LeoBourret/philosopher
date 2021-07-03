/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:10:21 by lebourre          #+#    #+#             */
/*   Updated: 2021/07/03 16:09:59 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define STATUS_EA		0
# define STATUS_SLEEP	1
# define STATUS_FORK	2
# define STATUS_THINK	3
# define STATUS_DIED	4
# define STATUS_SUCCESS	5
# define BAD_ARGUMENT "Error: there must be either 4 or 5 arguments. those argument are: : number_of_philosophers, time_to_die, time_to_eat, time_to_sleep and optionaly [number_of_times_each_philosopher_must_eat]"

struct	settings;

typedef struct s_philo
{
	int				position;
	int				last_meal;
	int				status;
	int				r_fork;
	int				l_fork;
	struct settings	*settings;
}				t_philo;


typedef struct s_settings
{
	int				philo_nb;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				meal_to_win;
	uint64_t		start;
	t_philo			*philos;
}

int		ft_strlen(const char *s);
int		ft_atoi(const char *s);
void	ft_putnbr(uint64_t n);

#endif
