/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:49:22 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/16 16:52:07 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	ft_usleep(1);
	while (philo->all_data->is_dead == false)
	{
		if (all_eat(philo) == true)
			break;
		is_eating(philo);
		ft_safe_print("is sleeping", philo);
		ft_usleep(philo->all_data->time_to_sleep);
		ft_safe_print("is thinking", philo);
	}
	return (phil);
}

int	all_eat(t_philo *philo)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while(i < philo->all_data->nb_philo)
	{
		if(philo[i].ate == philo[i].must_eat)
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

void	is_eating(t_philo *philo)
{
	if (philo->must_eat != none && philo->ate == philo->must_eat)
		return ;
	pthread_mutex_lock(&philo->left_fork);
	ft_safe_print("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	ft_safe_print("has taken a fork", philo);
	philo->last_meal = (int)get_current_time();
	philo->ate = philo->ate + 1;
	ft_safe_print("is eating", philo);
	ft_usleep(philo->all_data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

void	*monitoring(void *param)
{
	t_philo	*philo;
	int		i;
	int		time;

	philo = (t_philo *)param;
	i = 0;
	while (philo->all_data->is_dead == false)
	{
		ft_usleep(10);
		time = get_current_time();
		if (time - philo[i].last_meal >= philo->all_data->time_to_die)
		{
			ft_safe_print("is dead", &philo[i]);
			pthread_mutex_lock(&philo->all_data->dead_mtx);
			philo->all_data->is_dead = true;
			pthread_mutex_unlock(&philo->all_data->dead_mtx);
		}
		if (i == (philo->all_data->nb_philo - 1))
			i = 0;
		else
			i++;
	}
	return (philo);
}
