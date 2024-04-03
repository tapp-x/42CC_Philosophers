/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:57:13 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/03 15:42:26 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// INCLUDES

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// STRUCT

typedef enum s_bool
{
	true = 1,
	false = 0
}				t_bool;

typedef struct s_philo
{
	int				id;
	int				ate;
	int				last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_philo;

typedef struct s_all
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				is_dead;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*print_mtx;
	t_philo			*philo;
}				t_all;

// FUNCTIONS

int		ft_atoi(const char *nptr);
int		check_args(t_all *all);
int		init_data(int ac, char **av, t_all *all);
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);

#endif
