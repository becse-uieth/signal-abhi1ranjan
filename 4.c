#include<stdio.h>
#include<signal.h>
#include<unistd.h>

sig_atomic_t sum;

void sig_handler(int signo)
{
  if (signo == SIGINT)
    printf("received SIGINT\n");
  else if (signo == SIGSTOP)
        printf("received SIGSTOP\n");
}

int main(void)
{
	int i;
	if (signal(SIGINT, sig_handler) == SIG_ERR)
 	{
		 printf("\ncan't catch SIGINT\n");
	}
	if (signal(SIGSTOP, sig_handler) == SIG_ERR)
        {
		printf("\ncan't catch SIGSTOP\n");
	}
	i=0;
	while(i<10)
	{
		sum=sum+i;
		printf("%d %d\n",i,sum);
     		sleep(1);
		i++;
	}	
  return 0;
}
