/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebourre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:10:21 by lebourre          #+#    #+#             */
/*   Updated: 2021/07/06 20:12:56 by lebourre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

# define STATUS_THINK	0
# define STATUS_EAT		1
# define STATUS_SLEEP	2
# define STATUS_FORK	3
# define STATUS_DIED	4
# define STATUS_SUCCESS	5
# define BAD_ARGUMENT "Error: arguments not set properly.\n"
# define MALLOC_ERROR "Problem: malloc could not give set memory.\n"

struct	settings;

typedef struct s_philo
{
	int				position;
	u_int64_t		last_meal;
	int				status;
	int				r_fork;
	int				l_fork;
	struct settings	*settings;
}				t_philo;


typedef struct s_settings
{
	int				philo_nb;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	int				meal_to_win;
	u_int64_t		start;
	t_philo			*philos;
}				t_settings;

int			ft_strlen(const char *s);
u_int64_t	ft_atoi(const char *s);
void		ft_putnbr(u_int64_t n);
int			exit_error(char *s);
t_settings	*set_settings(int ac, char **av);

#endif
