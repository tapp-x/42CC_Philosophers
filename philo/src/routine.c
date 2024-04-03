/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:49:22 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/03 15:43:20 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(t_all *all)
{
	// pthread_mutex_init(all->print_mtx);
	prinft("[%d] %d is thinking\n", get_current_time(), all->philo->id);

}

void	is_eating(t_all *all)
{
	pthread_mutex_lock(); // lock left_fork
	
	pthread_mutex_lock(); // lock right_fork

}

void	ft_safe_printf(char *str, t_all *all)
{
	pthread_mutex_lock(all->print_mtx);
	printf("%s\n", str);
	pthread_mutex_unlock(all->print_mtx);
}
