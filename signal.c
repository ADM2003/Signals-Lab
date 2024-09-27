/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int handler_invoked = 0; 
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  handler_invoked = 1; //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1);
  while(1){
    if(handler_invoked){
      printf("Turing was right!\n");
      handler_invoked = 0;
      alarm(1);
    }
    pause();
  }
 
  return 0; //never reached
}