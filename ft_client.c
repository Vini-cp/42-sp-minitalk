/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:26:17 by vcordeir          #+#    #+#             */
/*   Updated: 2021/12/05 18:26:56 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_exit_failure(void)
{
	write(1, "Bad client parameters: Server PID and string", 44);
	exit(0);
}

static void	handler(int c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < BYTE_SIZE)
	{
		if ((c & 1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(SLEEP_TIME);
	}
}

static void	ft_send_message(char *message, int pid)
{
	int		i;
	int		message_len;

	i = 0;
	message_len = ft_strlen(message);
	while (i <= message_len)
	{
		handler(message[i], pid);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		ft_exit_failure();
	ft_send_message(argv[2], ft_atoi(argv[1]));
}
