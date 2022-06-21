/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 16:58:13 by drakan            #+#    #+#             */
/*   Updated: 2021/12/25 17:34:14 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_message(int signal)
{
	static int	symbol;
	static int	j;
	static int	i;

	if (j == 0)
		j = 128;
	if (signal == SIGUSR1)
		j /= 2;
	else if (signal == SIGUSR2)
	{
		symbol = symbol | j;
		j /= 2;
	}
	i++;
	if (i == 8)
	{
		if (symbol != 0)
			write(1, &symbol, 1);
		else
			write(1, "\n", 1);
		symbol = 0;
		i = 0;
		j = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("Server is running... PID is ");
	ft_putnbr(pid);
	ft_putstr(".\n");
	while (1)
	{
		signal(SIGUSR2, print_message);
		signal(SIGUSR1, print_message);
		pause();
	}
}
