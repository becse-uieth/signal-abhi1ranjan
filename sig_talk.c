/* sig_talk.c --- Example of how 2 processes can talk */
/* to each other using kill() and signal() */
/* We will fork() 2 process and let the parent send a few */
/* signals to it`s child  */


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sighup()
{  
   signal(SIGHUP,sighup); /* reset signal */
   printf("CHILD: I have received a SIGHUP\n");
}

void sigint()
{  
   signal(SIGINT,sigint); /* reset signal */
   printf("CHILD: I have received a SIGINT\n");
}

void sigquit()
{ 
  printf("My DADDY has Killed me!!!\n");
  exit(0);
}

int main()
{ 
    int pid;
                                                    /* get child process */
   if ((pid = fork()) < 0) 
   {
      perror("fork");
      exit(1);
   }   
   if (pid == 0)
   {                                                /* child */
      signal(SIGHUP,sighup);                        /* set function calls */
      signal(SIGINT,sigint);
      signal(SIGQUIT, sigquit);
      while(1);                                     /*infinite loop */
   }
  else                                              /* parent */
   {                                              /* pid hold id of child */
       printf("\nPARENT: sending SIGHUP\n\n");
       kill(pid,SIGHUP);
       sleep(3);                                    /* pause for 3 secs */
       printf("\nPARENT: sending SIGINT\n\n");
       kill(pid,SIGINT);
       sleep(3);                                    /* pause for 3 secs */
       printf("\nPARENT: sending SIGQUIT\n\n");
       kill(pid,SIGQUIT);
       sleep(3);
   }
     return 0;
}

