/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:57:13 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/15 17:11:23 by tappourc         ###   ########.fr       */
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

typedef enum e_bool
{
	true = 1,
	false = 0,
	none = -1,
	MAX_PHIL = 200
}					e_bool;

typedef struct s_philo
{
	int				id;
	int				ate;
	int				last_meal;
	int				start_time;
	struct s_all	*all_data;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	dead_mtx;
}					t_philo;

typedef struct s_all
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				is_dead;
	size_t			start_time;
	pthread_t		monit;
	pthread_mutex_t	dead_mtx;
	pthread_mutex_t	print_mtx;
	t_philo			*philo;
}					t_all;

// UTILS
int					ft_atoi(const char *nptr);
int					ft_usleep(size_t milliseconds);
size_t				get_current_time(void);
void				ft_safe_print(char *str, t_philo *philo);
void				free_all(t_all *all);
void				free_phil(t_philo *philo, int nb);

// INIT
int					check_args(t_all *all);
int					init_data(int ac, char **av, t_all *all);
void				init_forks(pthread_mutex_t *forks_tab, int philos);
int					init_philo(t_all *all, t_philo *philos, int nb,
						pthread_mutex_t *forks_tab);

// MONITOR
void				*routine(void *phil);
void				is_eating(t_philo *philo);
void				*monitoring(void *param);

#endif
