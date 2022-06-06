#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
  if (signo == SIGINT)
  printf("\nI'm melting!! mmeeellttiiiingg......\n" );
}

int main(void)
{
    int i=0;
  if (signal(SIGINT, sig_handler) == SIG_ERR)
  printf("\ncan't catch SIGINT\n");
  // A long long wait so that we can easily issue a signal to this process
  while(1) 
  {
      sleep(1);
      printf("%d",i+1);
       i++;
  
  }
   printf("\nI'm melting!! mmeeellttiiiingg......\n" );
   
  return 0;
}