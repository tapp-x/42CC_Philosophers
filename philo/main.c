/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:03:42 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/15 10:51:51 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		free_all(all);
		return (1);
	}
	init_forks(forks_tabs, all->nb_philo);
	if (init_philo(all, all->philo, all->nb_philo, forks_tabs) == false)
		printf("Failed to create thread\n");
	pthread_create(&all->monit, NULL, (void *)all->philo, &monitoring);
	// free_phil(all->philo, all->nb_philo);
	// free_all(all);
	return (0);
}
