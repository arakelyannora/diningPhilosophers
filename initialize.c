#include "philosophers.h"

void init(params *param, int argc, char **argv)
{
	param->number_of_philos = argv[1];
	param->time_to_die = argv[2];
	param->time_to_eat = argv[3];
	param->time_to_sleep = argv[4];
	if (argc == 6)
	{
		param->number_of_times_to_eat = argv[5];
	}
	else
	{
		param->number_of_times_to_eat = -1;
	}
}