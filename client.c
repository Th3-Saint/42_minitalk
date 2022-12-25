/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:28:51 by mrobaii           #+#    #+#             */
/*   Updated: 2022/03/01 01:39:31 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

char	*itob(int c)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc (sizeof(char) * 9);
	while (i < 9)
		str[i++] = 0;
	i = 7;
	while (i >= 0)
	{
		str[i] = c % 2 + '0';
		c = c / 2;
		i--;
	}
	return (str);
}

void	signal_sender(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	main(int ac, char **av)
{
	int		i;
	char	*str;
	int		pid;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0)
			return (0);
		while (av[2][i])
		{
			str = itob(av[2][i]);
			signal_sender(str, pid);
			free(str);
			i++;
		}
	}
	return (0);
}
