#include <stdio.h>
#include <signal.h>

void sigint_handler( int signo)
{
   int   ndx;

   printf( "Ctrl-C Ű�� �������.\n");
   printf( "3�ʰ� ����ϰڽ��ϴ�. �̶� Ctrl-ZŰ�� ���� �ּ���.\n");

   for ( ndx = 3; 0 < ndx; ndx--){
      printf( "%d �� ���ҽ��ϴ�.\n", ndx);
      sleep( 1);
   }
}

int main( void)
{
   struct sigaction act;

   act.sa_handler = sigint_handler;  // �ñ׳� �ڵ鷯 ����
   sigfillset( &act.sa_mask);        // ��� �ñ׳��� ���

   sigaction( SIGINT, &act, NULL);
   while(1 )
   {
      printf( "forum.falinux.com\n");
      sleep( 1);
   }
}