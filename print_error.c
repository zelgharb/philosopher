#include "philo.h"
void	error_exit(void)
{
	printf("Usage : ./philo num_of_philos time_to_die time_to_eat time_to_sleep *num_of_times_aphilo_must_eat\n");
	printf("[1 - 200] [0 - 2147483647] [0 - 2147483647] [0 - 2147483647] [>=0]\n");
	exit(1);
}
