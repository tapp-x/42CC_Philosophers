/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:49:22 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/08 14:30:37 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *phil)
{
	t_philo *philo;

	philo = (t_philo *)phil;
	ft_usleep(1);
	while(philo->ate < philo->all_data->must_eat) // fonction qui tcheck la mort en live pr tlmd
	{
		is_eating(philo);
		ft_safe_print("is sleeping", philo);
		ft_usleep(philo->all_data->time_to_sleep);
		ft_safe_print("is thinking", philo);
	}
	return (phil);
}

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	ft_safe_print("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	ft_safe_print("has taken a fork", philo);
	ft_safe_print("is eating", philo);
	philo->last_meal = (int)get_current_time();
	philo->ate += 1;
	ft_usleep(philo->all_data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

// dans la monitoring, check la diff entre curTime et lastmeal, si sup a t2die alors exit
// try avec exit pr commencer

void	monitoring(void *param)
{
	t_all	*all;
	int		i;

	all = (t_all *param);
	i = 0;
	while(true)
	{

	}

}
