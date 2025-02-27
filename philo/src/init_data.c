/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:49:13 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/21 17:00:33 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	launch_time(t_all *all);

int	init_data(int ac, char **av, t_all *all)
{
	pthread_mutex_init(&(all->dead_mtx), NULL);
	pthread_mutex_init(&(all->print_mtx), NULL);
	pthread_mutex_init(&(all->timer), NULL);
	all->nb_philo = ft_atoi(av[1]);
	all->time_to_die = ft_atoi(av[2]);
	all->time_to_eat = ft_atoi(av[3]);
	all->time_to_sleep = ft_atoi(av[4]);
	all->start_time = false;
	all->is_dead = false;
	if (ac == 6)
		all->must_eat = ft_atoi(av[5]);
	else
		all->must_eat = none;
	if (check_args(all) == false)
		return (false);
	all->philo = malloc(sizeof(t_philo) * all->nb_philo);
	if (!all->philo)
		return (false);
	return (true);
}

int	check_args(t_all *all)
{
	if (all->nb_philo < 1 || all->nb_philo > MAX_PHIL)
	{
		printf("'number_of_philosophers' must be in range [1-200]\n");
		return (false);
	}
	if (all->time_to_die < 60 || all->time_to_eat < 60
		|| all->time_to_sleep < 60)
	{
		printf("Time in 'ms' must be >= 60\n");
		return (false);
	}
	if (all->must_eat != none && (all->must_eat <= 0))
	{
		printf("'number_of_times_each_philosopher_must_eat' must be > 0\n");
		return (false);
	}
	return (true);
}

void	init_forks(pthread_mutex_t *forks_tab, int philos)
{
	int	i;

	i = 0;
	while (i < philos)
	{
		pthread_mutex_init(&forks_tab[i], NULL);
		i++;
	}
}

int	init_philo(t_all *all, t_philo *philos, int nb, pthread_mutex_t *forks_tab)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		philos[i].all_data = all;
		philos[i].ate = 0;
		philos[i].id = i + 1;
		philos[i].must_eat = all->must_eat;
		philos[i].last_meal = 0;
		philos[i].left_fork = forks_tab[i];
		pthread_mutex_init(&philos[i].meal, NULL);
		pthread_mutex_init(&philos[i].count_meal, NULL);
		if (i > 0)
			philos[i].right_fork = &(philos[i - 1].left_fork);
	}
	philos[0].right_fork = &(philos[nb - 1].left_fork);
	if (pthread_create(&all->monit, NULL, &monitoring, all) != 0)
		return (false);
	launch_time(all);
	return (true);
}

void	launch_time(t_all *all)
{
	int	i;
	int	time;

	i = -1;
	while (++i < all->nb_philo)
	{
		if (pthread_create(&all->philo[i].thread, NULL, &routine,
				&all->philo[i]) != 0)
			return ;
	}
	time = get_current_time();
	i = 0;
	while (i < all->nb_philo)
	{
		pthread_mutex_lock(&all->philo[i].meal);
		all->philo[i].last_meal = time;
		pthread_mutex_unlock(&all->philo[i].meal);
		i++;
	}
	pthread_mutex_lock(&all->timer);
	all->start_time = time;
	pthread_mutex_unlock(&all->timer);
}
