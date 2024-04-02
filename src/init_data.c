/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:49:13 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/02 11:43:26 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(int ac, char **av, t_all_data *all_data)
{
	all_data->nb_philo = ft_atoi(av[1]);
	all_data->time_to_die = ft_atoi(av[2]);
	all_data->time_to_eat = ft_atoi(av[3]);
	all_data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		all_data->must_eat = ft_atoi(av[5]);
	else
		all_data->must_eat = -1;
	if (check_args(all_data) == false)
		return (false);
	return (true);
}

int	check_args(t_all_data *all_data)
{
	if (all_data->nb_philo < 1 || all_data->nb_philo > 200)
	{
		printf("'number_of_philosophers' must be in range [1-200]\n");
		return (false);
	}
	if (all_data->time_to_die < 1 || all_data->time_to_eat < 1
		|| all_data->time_to_sleep < 1)
	{
		printf("Time in 'ms' must be positive value\n");
		return (false);
	}
	return (true);
}