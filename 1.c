#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>

sig_atomic_t EXIT_SUCCESS;

/*struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };
*/

int main()
{
	struct sigaction *old_sa;
	struct sigaction sa;
	memset(&sa, sizeof(sa),0);
	sa.sa_handler=SIG_DFL;
	sigaction(SIGINT,&sa,old_sa);
	sleep(10);
	int a,b,c;
	printf("Enter two no\n");
	scanf(" %d%d",&a,&b);
	c=a+b;
	printf("SUM=%d\n",c);
	return 0;
}
