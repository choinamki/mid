#include<stdio.h>
#include<signal.h>
#include<unistd.h>

struct sigaction act_new;
struct sigaction act_old;

void sigint_handler( int signo)
{
   printf( "ctrl + c");
   printf( "again exit.\n");
   sigaction( SIGINT, &act_old, NULL);
}

int main( void)
{
   
   act_new.sa_handler = sigint_handler; 
   sigemptyset( &act_new.sa_mask);      
                                                                                      
   sigaction( SIGINT, &act_new, &act_old); 
   while(1 )
   {
      printf( "forum.falinux.com\n");
      sleep( 1);
   }
}
