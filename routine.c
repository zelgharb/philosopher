#include "philo.h"

time_t get_timestamp_ms(void)
{
    struct timeval  tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}


void sleep_precise(time_t duration)
{
    time_t start = get_timestamp_ms();
    while (get_timestamp_ms() - start < duration)
        usleep(500);
}

void announce_action(t_guest *guest, char *msg)
{
    pthread_mutex_lock(&guest->room->print_lock);
    if (!guest->room->simulation_over)
        printf("%ld %d %s\n", get_timestamp_ms() - guest->room->start_time, guest->id, msg);
    pthread_mutex_unlock(&guest->room->print_lock);
}

void grab_utensils(t_guest *guest)
{
    if (guest->id % 2 == 0)
    {
        // Philosophe pair : prend la 2e fourchette, puis la 1ère
        pthread_mutex_lock(&guest->room->forks[guest->second_fork]);
        announce_action(guest, "has taken his second fork");

        pthread_mutex_lock(&guest->room->forks[guest->first_fork]);
        announce_action(guest, "has taken his first fork");
    }
    else
    {
        // Philosophe impair : prend la 1ère fourchette, puis la 2e
        pthread_mutex_lock(&guest->room->forks[guest->first_fork]);
        announce_action(guest, "has taken his first fork");

        pthread_mutex_lock(&guest->room->forks[guest->second_fork]);
        announce_action(guest, "has taken his second fork");
    }
}


void release_utensils(t_guest *guest)
{
    pthread_mutex_unlock(&guest->room->forks[guest->first_fork]);
    pthread_mutex_unlock(&guest->room->forks[guest->second_fork]);
}
void dine(t_guest *guest)
{
    pthread_mutex_lock(&guest->meal_lock);
    guest->last_meal = get_timestamp_ms();
    pthread_mutex_unlock(&guest->meal_lock);

    announce_action(guest, "is eating");
    sleep_precise(guest->room->time_to_eat);
    
    pthread_mutex_lock(&guest->meal_lock);
    guest->meals_eaten++;
    pthread_mutex_unlock(&guest->meal_lock);
}
void take_nap(t_guest *guest)
{
    announce_action(guest, "is sleeping");
    sleep_precise(guest->room->time_to_sleep);
}

void reflect(t_guest *guest)
{
    announce_action(guest, "is thinking");
}

void *guest_routine(void *arg)
{
    t_guest *guest = (t_guest *)arg;

    while (!guest->room->simulation_over)
    {
        grab_utensils(guest);
        dine(guest);
        release_utensils(guest);
        take_nap(guest);
        reflect(guest);
    }
    return NULL;
}



