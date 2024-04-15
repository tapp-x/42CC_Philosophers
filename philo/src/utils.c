/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:51:07 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/15 10:35:05 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_phil(t_philo *philo, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&philo[i].left_fork);
		pthread_mutex_destroy(philo[i].right_fork);
		pthread_mutex_destroy(&philo[i].dead_mtx);
		pthread_mutex_destroy(&philo[i].print_mtx);
		free(&philo[i]);
		i++;
	}
}

void	free_all(t_all *all)
{
	pthread_mutex_destroy(&all->dead_mtx);
	pthread_mutex_destroy(&all->print_mtx);
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

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_safe_print(char *str, t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&(philo->print_mtx));
	time = get_current_time() - philo->start_time;
	if (time >= 0 && time <= 2147483647)
		printf("[%d] %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&(philo->print_mtx));
}
