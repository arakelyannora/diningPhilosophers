#include "philosophers.h"

int main(int argc, char** argv)
{
	params param;

	if (argc == 5 || argc == 6)
	{
		init(&param, argc, argv);
	}
	else
	{
		errors(WRONG_PARAMS_NUMBER);
	}
	for (int i = 0; argv[i]; i++)
		printf("%s\n", argv[i]);
	return (0);
}