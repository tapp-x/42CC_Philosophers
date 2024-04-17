/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:12:00 by tappourc          #+#    #+#             */
/*   Updated: 2024/04/17 20:30:30 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_is_space(char c)
{
	if ((c > 7 && c < 14) || (c == 32))
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	neg = 1;
	while (nptr[i] != '\0')
	{
		while (ft_is_space(nptr[i]) == 0)
			i++;
		if ((nptr[i] == 43) || (nptr[i] == 45))
		{
			if (nptr[i] == 45)
				neg *= -1;
			i++;
		}
		while (nptr[i] > 47 && nptr[i] < 58)
		{
			nb = nb * 10 + (nptr[i] - '0');
			i++;
		}
		return (nb * neg);
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!s1 || !s2)
		return (-1);
	while (i < n && str1[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if ((i < n && i == 0) || (str2[i] != '\0' && i < n))
		return (-str2[i]);
	return (0);
}
