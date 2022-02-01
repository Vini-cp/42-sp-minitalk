/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:52:02 by coder             #+#    #+#             */
/*   Updated: 2022/02/01 22:53:05 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define SLEEP_TIME 100
# define BYTE_SIZE 8

int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_itoa(int num);
char	*ft_concatenate(char const *str, char c);
char	*ft_strdup(const char *s);

#endif
