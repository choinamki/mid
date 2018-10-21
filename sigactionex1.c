#include <stdio.h>
#include <signal.h>

struct sigaction act_new;
struct sigaction act_old;

void sigint_handler( int signo)
{
   printf( "Ctrl-C Ű�� �������!!\n");
   printf( "�� �����ø� ����˴ϴ�.\n");
   sigaction( SIGINT, &act_old, NULL);
}

int main( void)
{
   
   act_new.sa_handler = sigint_handler; // �ñ׳� �ڵ鷯 ����
   sigemptyset( &act_new.sa_mask);      // �ñ׳� ó�� �� ��ϵ� �ñ׳��� ����
                                           
   // SIGINT�� �����ϸ鼭 act_old�� ���� ������ ���մϴ�.                                           
   sigaction( SIGINT, &act_new, &act_old); 
   while(1 )
   {
      printf( "forum.falinux.com\n");
      sleep( 1);
   }
}