/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:57:13 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/02 11:41:34 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// INCLUDES

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// STRUCT

typedef enum s_bool
{
	true = 1,
	false = 0
}				t_bool;

typedef struct s_all_data
{
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
}				t_all_data;

typedef struct s_philo
{
	int			id;
	int			ate;
	int			is_dead;
	int			last_meal;
	t_all_data	*all_data;
}				t_philo;

// FUNCTIONS

int				ft_atoi(const char *nptr);
int				check_args(t_all_data *all_data);
int				init_data(int ac, char **av, t_all_data *all_data);

#endif
