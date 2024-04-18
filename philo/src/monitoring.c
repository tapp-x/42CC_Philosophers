/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:43:52 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/18 15:32:04 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_eat(t_all *all);

void	*monitoring(void *param)
{
	t_all	*all;

	all = (t_all *)param;
	while (true)
	{
		if (!check_death(all))
			break ;
		if (all->must_eat != none)
			all_eat(all);
		ft_usleep(5);
	}
	return (all);
}

void	all_eat(t_all *all)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < all->nb_philo)
	{
		pthread_mutex_lock(&all->philo[i].count_meal);
		if (all->philo[i].ate == all->must_eat)
			count++;
		pthread_mutex_unlock(&all->philo[i].count_meal);
		i++;
	}
	if (count == all->nb_philo - 1)
	{
		pthread_mutex_lock(&all->dead_mtx);
		all->is_dead = true;
		pthread_mutex_unlock(&all->dead_mtx);
	}
}

int	check_death(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->nb_philo)
	{
		if (check_meal(&all->philo[i]) == false
			|| a_philo_is_dead(&all->philo[i]) == true)
			return (false);
	}
	return (true);
}

int	check_meal(t_philo *philo)
{
	int	time;

	time = get_current_time();
	pthread_mutex_lock(&philo->meal);
	if ((time - philo->last_meal) > philo->all_data->time_to_die)
	{
		pthread_mutex_unlock(&philo->meal);
		pthread_mutex_lock(&philo->all_data->dead_mtx);
		philo->all_data->is_dead = true;
		pthread_mutex_unlock(&philo->all_data->dead_mtx);
		ft_safe_print("is dead ----------- debug", philo);
		return (false);
	}
	pthread_mutex_unlock(&philo->meal);
	return (true);
}

int	a_philo_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->all_data->dead_mtx);
	if (philo->all_data->is_dead == true)
	{
		pthread_mutex_unlock(&philo->all_data->dead_mtx);
		return (true);
	}
	pthread_mutex_unlock(&philo->all_data->dead_mtx);
	return (false);
}
