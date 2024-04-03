/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:03:42 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/03 15:18:57 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo		**philo;
	t_all	*all;
	int			test;

	test = ft_atoi(av[1]);
	(void)philo;
	(void)test;
	if (ac < 5 || ac > 6)
	{
		printf("Invalid num of args\n");
		return (1);
	}
	all = malloc(sizeof(t_all));
	if (!all)
		return (1);
	if (init_data(ac, av, all) == false)
	{
		free(all);
		return (1);
	}
	printf("[%lu]\n", get_current_time());
	return (0);
}
