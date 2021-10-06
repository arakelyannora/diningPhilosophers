#include "philosophers.h"

void errors(int error_number)
{
    if (error_number == 0)
    {
        printf("Wrong number of params\n");
    }
    printf("Usage: ./philosophers number_of_philos time_to_die\
    time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat\n");
}