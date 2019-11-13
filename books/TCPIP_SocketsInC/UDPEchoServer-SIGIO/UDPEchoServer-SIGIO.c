#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include <signal.h>
#include <errno.h>

#define ECHOMAX 255

void useIdleTime();
void SIGIOHandler(int signalType);

int sock;


int main(int argc, char *argv[])
{
  struct sockaddr_in echoServAddr;
  unsigned short echoServPort;
  struct sigaction handler;

  if(argc != 2)
  {
    fprintf(stderr, "Usage: %s <SERVER PORT>\n", argv[0]);
    exit(1);
  }

  echoServPort = atoi(argv[1]);

  if((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    dieWithError("socket() failed");

  memset(&echoServAddr, 0, sizeof(echoServAddr));
  echoServAddr.sin_family = AF_INET;
  echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  echoServAddr.sin_port = htons(echoServPort);

  if(bind(sock, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) < 0)
    dieWithError("bind() failed");

  handler.sa_handler = SIGIOHandler;

  if(sigfillset(&handler.sa_mask) < 0)
    dieWithError("sigaction() failed for SIGIO");

  if(fcntl(sock, F_SETOWN, getpid()) < 0)
    dieWithError("Unable to set process owner to us");

  if(fcntl(sock, F_SETFL, O_NONBLOCK | FASYNC) < 0)
    dieWithError("Unable to pit client sock into nonblocking/async mode");

  for(;;)
    useIdleTime();

  return EXIT_SUCCESS;
}

void useIdleTime()
{
  printf(".\n");
  sleep(3);
}

void SIGIOHandler(int signalType)
{

  struct sockaddr_in echoClntAddr;
  unsigned int clntLen;
  int recvMsgSize;
  char echoBuffer[ECHOMAX];

  do{
    clntLen = sizeof(echoClntAddr);

    if((recvMsgSize = recvfrom(sock, echoBuffer, ECHOMAX, 0, (struct sockaddr *)&echoClntAddr, &clntLen)) < 0)
    {
      if(errno != EWOULDBLOCK)
        dieWithError("recvfrom() failed");
    }
    else
    {
      printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));

      if(sendto(sock, echoBuffer, recvMsgSize, 0, (struct sockaddr *)&echoClntAddr, sizeof(echoClntAddr)) != recvMsgSize)
        dieWithError("sendto() failed");
    }
  }while(recvMsgSize >= 0);
}
