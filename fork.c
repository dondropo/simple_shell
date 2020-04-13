#include "holberton.h"


int main(void)
{
	int chk = 33;
	pid_t iden;

	printf("** process id = %d, start **\n", getpid());
	iden = fork();

	printf("process id = %d, iden = %d executing \n", getpid(), iden);

	if (iden > 0)
	{
		chk = 44;
	}
	else if (iden == 0)
	{
		chk = 55;
	}
	else
	{
		return (0);
	}
	while (1)
	{
		sleep(2);
		printf("process id = %d, chk = %d executing \n", getpid(), chk);
	}
	return (0);
}
