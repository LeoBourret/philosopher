#include <stdio.h>
#include <stdlib.h>
#include "philo.h"

int		main()
{
	u_int64_t start;

	start = get_time();
	printf("salut\n");
	while (1)
	{
		printf("%llu\n", get_exec_time(start));
		usleep(150000);
	}
}
