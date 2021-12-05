#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define SLEEP_TIME 100
# define BYTE_SIZE 8

int	  ft_strlen(const char *s);
int	  ft_atoi(const char *str);
char	*ft_itoa(int num);
char  *ft_concatenate(char const *str, char c);
char	*ft_strdup(const char *s);

#endif