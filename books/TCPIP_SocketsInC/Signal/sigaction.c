#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <util/util.h>

void interruptSignalHandler(int signalType);

int main(int argc, char *argv[])
{
  struct sigaction handler;

  handler.sa_handler = interruptSignalHandler;
  if(sigfillset(&handler.sa_mask) < 0)
    dieWithError("sigfillset() failed");

  handler.sa_flags = 0;

  if(sigaction(SIGINT, &handler, 0) < 0)
    dieWithError("sigaction() failed");

  for(;;)
    pause();
  
  return EXIT_SUCCESS;
}

void interruptSignalHandler(int signalType)
{
  printf("Interrupt Received. Exiting program.\n");
  exit(1);
}
