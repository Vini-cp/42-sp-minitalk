/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:27:11 by vcordeir          #+#    #+#             */
/*   Updated: 2021/12/05 18:30:39 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_reset_vars(int *c, int *p)
{
	*c = 0;
	*p = 0;
}

static void	ft_print_message(char **str)
{
	write(1, *str, ft_strlen(*str));
	write(1, "\n", 1);
	free(*str);
	*str = NULL;
}

static void	handler(int signum)
{
	static int	bit;
	static int	msg_char;
	static char	*message;

	if (signum == SIGUSR1)
		msg_char += 1 << bit;
	bit++;
	if (bit == BYTE_SIZE)
	{
		if (msg_char)
			message = ft_concatenate(message, msg_char);
		else
			ft_print_message(&message);
		ft_reset_vars(&msg_char, &bit);
	}
}

static void	ft_print_pid(int pid)
{
	char	*pid_str;

	pid_str = ft_itoa(pid);
	write(1, "PID: ", 5);
	write(1, pid_str, ft_strlen(pid_str));
	write(1, "\n", 1);
	free(pid_str);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
		return (1);
	ft_print_pid(getpid());
	while (1)
		pause();
}
