/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:51:07 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/05 11:07:19 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	long	time;
	
	pthread_mutex_lock(&(philo->all_data.print_mtx));
	time = get_current_time() - philo->all_data.start_time;
	if (time <= 0 && time <= INT_MAX)
		printf("[%ld] %d %s\n",time, philo->id, str);
	pthread_mutex_unlock(&(philo->all_data.print_mtx));
}