/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:03:42 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/02 11:34:39 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo		**philo;
	t_all_data	*all_data;
	int			test;

	test = ft_atoi(av[1]);
	(void)philo;
	(void)test;
	if (ac < 5 || ac > 6)
	{
		printf("Invalid num of args\n");
		return (1);
	}
	all_data = malloc(sizeof(t_all_data));
	if (!all_data)
		return (1);
	if (init_data(ac, av, all_data) == false)
	{
		free(all_data);
		return (1);
	}
	printf("start\n");
	return (0);
}
