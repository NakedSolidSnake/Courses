#include <servertcp/servertcp.h>
#include <util/util.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *ThreadMain(void *arg);

struct ThreadArgs
{
  int clntSock;
};

int main(int argc, char *argv[])
{
  int servSock;
  int clntSock;
  unsigned short echoServPort;
  pthread_t threadID;
  struct ThreadArgs *threadArgs;

  if(argc != 2)
  {
    fprintf(stderr, "Usage: %s <SERVER PORT>\n", argv[0]);
    exit(1);
  }

  echoServPort = atoi(argv[1]);

  servSock = createTCPServerSocket(echoServPort);

  for(;;)
  {

    clntSock = acceptTCPConnection(servSock);
    if((threadArgs = (struct ThreadArgs *) malloc(sizeof(struct ThreadArgs))) == NULL)
      dieWithError("malloc() failed");

    threadArgs->clntSock = clntSock;

    if(pthread_create(&threadID, NULL, ThreadMain, (void *)threadArgs) != 0)
      dieWithError("pthread_create() failed");

    printf("with thread %ld\n", (long int)threadID);
  }
}

void *ThreadMain(void *threadArgs)
{
  int clntSock;

  pthread_detach(pthread_self());

  clntSock = ((struct ThreadArgs *) threadArgs)->clntSock;
  free(threadArgs);

  handleTCPClient(clntSock);

  return(NULL);
}
