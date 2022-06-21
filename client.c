/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:42:31 by drakan            #+#    #+#             */
/*   Updated: 2021/12/27 19:39:13 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		j = 128;
		while (j != 0)
		{
			usleep(75);
			if (str[i] & j)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j /= 2;
		}
		if (str[i] == '\0')
		{
			ft_putstr("The message was sent to the server\n");
			break ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
		ft_putstr("Usage: ./client [PID] [message]\n");
	else
	{
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2]);
	}
}
