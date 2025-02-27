/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:03:42 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/21 15:10:41 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	keep_thread(t_all *all);

int	main(int ac, char **av)
{
	t_all			*all;
	pthread_mutex_t	forks_tabs[MAX_PHIL];

	if (ac < 5 || ac > 6)
	{
		printf("Invalid num of args\n");
		return (1);
	}
	all = malloc(sizeof(t_all));
	if (!all)
		return (1);
	if (init_data(ac, av, all) == false)
	{
		free(all);
		return (1);
	}
	init_forks(forks_tabs, all->nb_philo);
	if (init_philo(all, all->philo, all->nb_philo, forks_tabs) == false)
		printf("Failed to create thread\n");
	pthread_mutex_lock(&all->dead_mtx);
	keep_thread(all);
	free_phil(all);
	return (0);
}

void	keep_thread(t_all *all)
{
	while (all->is_dead == false)
	{
		pthread_mutex_unlock(&all->dead_mtx);
		ft_usleep(1);
		pthread_mutex_lock(&all->dead_mtx);
	}
	pthread_mutex_unlock(&all->dead_mtx);
}
