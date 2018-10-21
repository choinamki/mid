#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sigint_handler( int signo)
{
   int   ndx;

   printf( "ctrl-c press");
   printf( "3second wait ctrl -z exit.\n");

   for ( ndx = 3; 0 < ndx; ndx--){
      printf( "%d second.\n", ndx);
      sleep( 1);
   }
}

int main( void)
{
   struct sigaction act;

   act.sa_handler = sigint_handler;  
   sigfillset( &act.sa_mask);       

   sigaction( SIGINT, &act, NULL);
   while(1 )
   {
      printf( "forum.falinux.com\n");
      sleep( 1);
   }
}
