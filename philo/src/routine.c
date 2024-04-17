/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:49:22 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/17 20:09:16 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	waiting_start(t_philo *philo);

void	*routine(void *phil)
{
	t_philo	*philo;
	philo = (t_philo *)phil;
	// ft_safe_print("ENTER ROUTINE", philo);
	// pthread_mutex_lock(&philo->all_data->timer);
	// while(philo->all_data->start_time != false)
	// {
	// 	pthread_mutex_unlock(&philo->all_data->timer);
	// 	ft_usleep(1);
	// 	pthread_mutex_lock(&philo->all_data->timer);

	// }
	// pthread_mutex_unlock(&philo->all_data->timer);
	// while (check_death(philo->all_data) == true)
	waiting_start(philo);
	if (philo->id % 2 == 0)
		ft_usleep(20);
	pthread_mutex_lock(&philo->all_data->dead_mtx);
	while (philo->all_data->is_dead == false)
	{
		pthread_mutex_unlock(&philo->all_data->dead_mtx);
		is_eating(philo);
		ft_safe_print("is sleeping", philo);
		ft_usleep(philo->all_data->time_to_sleep);
		ft_safe_print("is thinking", philo);
		ft_usleep(1);
		pthread_mutex_lock(&philo->all_data->dead_mtx);
	}
	pthread_mutex_unlock(&philo->all_data->dead_mtx);
	return (phil);
}

void	waiting_start(t_philo *philo)
{
	pthread_mutex_lock(&philo->all_data->timer);
	while(!philo->all_data->start_time)
	{
		pthread_mutex_unlock(&philo->all_data->timer);
		ft_usleep(1);
		pthread_mutex_lock(&philo->all_data->timer);

	}
	pthread_mutex_unlock(&philo->all_data->timer);
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	ft_safe_print("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	ft_safe_print("has taken a fork", philo);
	pthread_mutex_lock(&philo->meal);
	philo->last_meal = (int)get_current_time();
	pthread_mutex_unlock(&philo->meal);
	ft_safe_print("is eating", philo);
	ft_usleep(philo->all_data->time_to_eat);
	philo->ate += 1;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}
