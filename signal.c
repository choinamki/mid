#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

static void sig_usr(int signo)
{
	if(signo == SIGUSR1)
		printf("received sigusr1\n");
	else if(signo == SIGUSR2)
		printf("received sigusr2\n");
	else if(signo == SIGTERM)
		printf("received sigterm, die hard)\n");
}
int main(void)
{
	if(signal(SIGUSR1, sig_usr) == SIG_ERR)
		perror("can't catch sigusr\n");
	if(signal(SIGUSR2, sig_usr) == SIG_ERR)
		perror("can't catch sigusr2\n");
	if(signal(SIGTERM, sig_usr) == SIG_ERR)
		perror("cannot catch sigterm\n");
	for(;;)
		sleep(60);
}
