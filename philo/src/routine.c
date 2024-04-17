/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:49:22 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/17 12:51:42 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	while (a_philo_is_dead(philo) == false)
	{
		if (a_philo_is_dead(philo) == true)
			return (phil);
		if (is_eating(philo) == false)
			return (phil);
		if (a_philo_is_dead(philo) == true)
			return (phil);
		ft_safe_print("is sleeping", philo);
		ft_usleep(philo->all_data->time_to_sleep);
		if (a_philo_is_dead(philo) == true)
			return (phil);
		ft_safe_print("is thinking", philo);
	}
	return (phil);
}

int	is_eating(t_philo *philo)
{
	if (philo->must_eat != none && philo->ate == philo->must_eat)
		return (false);
	if (philo->all_data->nb_philo == 1)
	{
		ft_usleep(philo->all_data->time_to_die + 1);
		return (false);
	}
	pthread_mutex_lock(&philo->left_fork);
	ft_safe_print("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	ft_safe_print("has taken a fork", philo);
	ft_safe_print("is eating", philo);
	philo->last_meal = (int)get_current_time();
	philo->ate += 1;
	ft_usleep(philo->all_data->time_to_eat);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (true);
}

int	all_eat(t_philo *philo)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < philo->all_data->nb_philo)
	{
		if (philo[i].ate == philo[i].must_eat)
			count++;
		i++;
	}
	if (count == (philo->all_data->nb_philo))
	{
		pthread_mutex_lock(&philo->all_data->dead_mtx);
		philo->all_data->is_dead = true;
		pthread_mutex_unlock(&philo->all_data->dead_mtx);
		return (true);
	}
	return (false);
}
