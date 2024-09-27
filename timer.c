#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int seconds = 0; 
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  seconds++;
  alarm(1);
}

void sigint_handler(int signum){
  printf("\nProgram ran for %d seconds.\n", seconds);
  exit(0);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT,sigint_handler);
  alarm(1); //Schedule a SIGALRM for 1 second
  while(1){
    pause();
  }  
  return 0; //never reached
}