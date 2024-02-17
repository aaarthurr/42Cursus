// void	error_management(int error_code)
// {
	
// }

void	*func1(void *arg)
{
	int i = 0;
	while (i++ < 5000)
	{
		printf("\033[31mThread 1: %d\033[0m\n", i);
		usleep(1000);
	}
	pthread_exit(NULL);
}

void	*func2(void *arg)
{
	int i = 0;
	while (i++ < 5000)
	{
		printf("\033[36mThread 2: %d\033[0m\n", i);
		usleep(10000);
	}
	pthread_exit(NULL);
}