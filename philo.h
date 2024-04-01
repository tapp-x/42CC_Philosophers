/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:57:13 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/01 10:46:40 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

typedef enum s_bool
{
	true = 1,
	false = 0
}			t_bool;

struct s_philo
{
	int		table_place;
	int		is_dead;
	int		meal_to_eat;
	int		philo_total_nb;
	size_t	last_meal;
	size_t	time_to_sleep;
	size_t	time_to_think;
	size_t	time_to_eat;

}		p_philo;


#endif
