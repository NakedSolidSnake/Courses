#include <servertcp/servertcp.h>
#include <util/util.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


void ProcessMain(int servSock);

int main(int argc, char *argv[])
{
  int servSock;
  unsigned short echoServPort;
  pid_t processID;
  unsigned int processLimit;
  unsigned int processCt;

  if(argc != 3)
  {
    fprintf(stderr, "Usage: %s <SERVER PORT> <FORK LIMIT>\n", argv[0]);
    exit(1);
  }

  echoServPort = atoi(argv[1]);
  processLimit = atoi(argv[2]);

  servSock = createTCPServerSocket(echoServPort);

  for(processCt = 0; processCt < processLimit; processCt++)
  {
    if((processID = fork()) < 0)
      dieWithError("fork() failed");
    else if(processID == 0)
      ProcessMain(servSock);
  }

  exit(0);
}

void ProcessMain(int servSock)
{
  int clntSock;

  for(;;)
  {
    clntSock = acceptTCPConnection(servSock);
    printf("with child process: %d\n", (unsigned int)getpid());
    handleTCPClient(clntSock);
  }
}

