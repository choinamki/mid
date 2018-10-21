#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<signal.h>

static void sig_usr(int signo)
{
	if(signo == SIGINT )
	{
		printf("\n");
		printf("received SIGINT");
		pirntf("\n");
		alarm(1);
	}
}

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
	{
		pause();
		if(signal(SIGINT, sig_usr) == SIG_ERR)
			perror("can't catch SIGINT");
	}
	exit(EXIT_SUCCESS);
}

