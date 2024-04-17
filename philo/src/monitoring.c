/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:43:52 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/17 16:20:07 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitoring(void *param)
{
	t_all	*all;

	all = (t_all *)param;
	while (true)
	{
		pthread_mutex_lock(&all->dead_mtx);
		if (check_death(all) == false)
		{
			// ft_usleep(10);
			pthread_mutex_unlock(&all->dead_mtx);
			break ;
		}
		pthread_mutex_unlock(&all->dead_mtx);
		// ft_usleep(1);
	}
	return (all);
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
		pthread_mutex_lock(&philo->dead_mtx);
		philo->all_data->is_dead = true;
		pthread_mutex_unlock(&philo->dead_mtx);
		ft_safe_print("is dead ----------- debug", philo);
		pthread_mutex_unlock(&philo->meal);
		return (false);
	}
	pthread_mutex_unlock(&philo->meal);
	return (true);
}

int	a_philo_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->dead_mtx);
	if (philo->all_data->is_dead == true)
	{
		pthread_mutex_unlock(&philo->dead_mtx);
		return (true);
	}
	pthread_mutex_unlock(&philo->dead_mtx);
	return (false);
}
