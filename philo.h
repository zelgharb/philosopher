#ifndef PHILO_H
#define PHILO_H
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

// typedef struct s_configue
// {
//     int             nb_philos;
//     time_t          time_to_die;
//     time_t          time_to_eat;
//     time_t          time_to_sleep;
//     pthread_mutex_t *forks;
//     int             stop_simulation;
//     pthread_mutex_t print_lock;
// }   t_configue;

// typedef struct s_philo
// {
//     int             id;
//     int             left_fork;
//     int             right_fork;
//     int             first_fork;
//     int             second_fork;
//     time_t          last_meal;
//     t_configue         *table;
//     pthread_mutex_t meal_time_lock;
// }   t_philo;

typedef struct s_dining_room
{
    int             nb_guests;
    time_t          start_time;
    time_t          time_to_die;
    time_t          time_to_eat;
    time_t          time_to_sleep;
    int             meals_required;

    pthread_mutex_t *forks;
    pthread_mutex_t print_lock;
    int             simulation_over;

    struct s_guest  *guests;

}               t_dining_room;

typedef struct s_guest
{
    int                 id;
    int                 first_fork;
    int                 second_fork;
    time_t              last_meal;
    int                 meals_eaten;

    pthread_mutex_t     meal_lock;
    t_dining_room       *room;

}               t_guest;


char	**ft_split(char const *s, char c);
void	error_exit(void);
int	main(int ac, char **av);
int    parse_args(int argc, char **argv);
// routine
time_t get_timestamp_ms(void);
void sleep_precise(time_t duration);
void announce_action(t_guest *guest, char *msg);
void grab_utensils(t_guest *guest);
void release_utensils(t_guest *guest);
void dine(t_guest *guest);
void take_nap(t_guest *guest);
void reflect(t_guest *guest);
void *guest_routine(void *arg);

#endif