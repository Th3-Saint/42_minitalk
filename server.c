/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 02:08:42 by mrobaii           #+#    #+#             */
/*   Updated: 2022/03/01 22:13:30 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}		
}

void	my_handler(int sig)
{
	static char	c;
	static int	i = 7;

	if (sig == SIGUSR1)
		c |= 0 << i;
	else
		c |= 1 << i;
	i--;
	if (i == -1)
	{
		write(1, &c, 1);
		i = 7;
		c = 0;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, my_handler);
	signal(SIGUSR2, my_handler);
	while (1)
		pause();
}
