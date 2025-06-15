#ifndef PHILO_H
#define PHILO_H
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);
void	error_exit(const char *msg);
void	error_exit(const char *msg);
int	main(int ac, char **av);
int    parse_args(int argc, char **argv);
#endif