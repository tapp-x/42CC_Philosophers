/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:49:13 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/03 14:39:58 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(int ac, char **av, t_all *all)
{
	all->nb_philo = ft_atoi(av[1]);
	all->time_to_die = ft_atoi(av[2]);
	all->time_to_eat = ft_atoi(av[3]);
	all->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		all->must_eat = ft_atoi(av[5]);
	else
		all->must_eat = -1;
	if (check_args(all) == false)
		return (false);
	return (true);
}

int	check_args(t_all *all)
{
	if (all->nb_philo < 1 || all->nb_philo > 200)
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
	return (true);
}
