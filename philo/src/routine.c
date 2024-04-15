/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:49:22 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/15 17:11:52 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	ft_usleep(1);
	while (true)
	{
		is_eating(philo);
		ft_safe_print("is sleeping", philo);
		ft_usleep(philo->all_data->time_to_sleep);
		ft_safe_print("is thinking", philo);
		if (philo->id == (philo->all_data->nb_philo - 1)
			&& philo->ate == philo->all_data->must_eat)
		{
			pthread_mutex_lock(&(philo->print_mtx));
			printf("All philos ate\n");
			pthread_mutex_unlock(&(philo->print_mtx));
			exit(1) ;
		}
	}
	return (phil);
}

// int	all_eat(t_philo *philo)
// {
// 	int	i;
	
// 	i = 0;
// 	count = 0;
// 	while(i < philo->all_data->nb_philo)
// 	{
// 		if(philo[i].ate == philo->all_data->must_eat)
// 			philo->all_data->finished += 1;
// 		i++;
// 	}
// 	if (i == count)
// 		return (true);
// 	return (false);
// }

void	is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	ft_safe_print("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	ft_safe_print("has taken a fork", philo);
	ft_safe_print("is eating", philo);
	philo->last_meal = (int)get_current_time();
	philo->ate = philo->ate + 1;
	// if (philo->ate == philo->all_data->must_eat)
	// 	philo->all_data->finished += 1;
	ft_usleep(philo->all_data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

// dans la monitoring, check la diff entre curTime et lastmeal,
// si sup a t2die alors exit
// try avec exit pr commencer

void	*monitoring(void *param)
{
	t_philo	*philo;
	int		i;
	int		time;

	philo = (t_philo *)param;
	i = 0;
	while (true)
	{
		ft_usleep(10);
		time = get_current_time();
		if (time - philo[i].last_meal >= philo->all_data->time_to_die)
		{
			ft_safe_print("is dead", &philo[i]);
			break ;
		}
		if (i == (philo->all_data->nb_philo - 1))
			i = 0;
		else
			i++;
	}
	return (philo);
}
