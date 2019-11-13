#include <servertcp/servertcp.h>
#include <util/util.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int servSock;
  int clntSock;
  unsigned short echoServPort;
  pid_t processID;

  unsigned int childProcCount = 0;

  if(argc != 2)
  {
    fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]);
    exit(1);
  }

  echoServPort = atoi(argv[1]);

  servSock = createTCPServerSocket(echoServPort);

  for(;;)
  {
    clntSock = acceptTCPConnection(servSock);

    if((processID = fork()) < 0)
      dieWithError("fork() failed");
    else if(processID == 0)
    {
      //child process 
      close(servSock);
      handleTCPClient(clntSock);
      exit(0);
    }

    printf("with child process: %d\n", (int)processID);
    close(clntSock);
    childProcCount++;

    while(childProcCount)
    {
      processID = waitpid((pid_t) -1, NULL, WNOHANG);
      if(processID < 0)
        dieWithError("waitpid() failed");
      else if(processID == 0)
        break;

      else 
        childProcCount--;
    }
  }
}
