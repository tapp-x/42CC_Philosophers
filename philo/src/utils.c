/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:51:07 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/18 14:46:53 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_phil(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->nb_philo)
	{
		pthread_join(all->philo[i].thread, NULL);
		i++;
	}
	pthread_join(all->monit, NULL);
	free(all->philo);
	free(all);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	ft_safe_print(char *str, t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->all_data->dead_mtx);
	if (philo->all_data->is_dead == true && ft_strncmp(str, "is dead", 7) != 0)
	{
		pthread_mutex_unlock(&philo->all_data->dead_mtx);
		return ;
	}
	pthread_mutex_unlock(&philo->all_data->dead_mtx);
	pthread_mutex_lock(&(philo->all_data->timer));
	time = get_current_time() - philo->all_data->start_time;
	pthread_mutex_unlock(&(philo->all_data->timer));
	if (time >= 0 && time <= 2147483647)
	{
		pthread_mutex_lock(&(philo->all_data->print_mtx));
		printf("[%d] %d %s\n", time, philo->id, str);
		pthread_mutex_unlock(&(philo->all_data->print_mtx));
	}
}
