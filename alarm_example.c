#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<signal.h>

void clock_tick(int signo)
{
	printf("before\n");
	printf("\r%ld", time(NULL));
	alarm(1);
	printf("\n");
	printf("after\n");
}

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, BUFSIZ);
	printf("\e[2J\e[H");

	if(signal(SIGALRM, clock_tick) == SIG_ERR)
		perror("can't catch SIGALRM");
	
	clock_tick(-1);
	
	//alarm(1);	

	printf("in?\n");

	for(;;)
		pause();
	exit(EXIT_SUCCESS);
}

