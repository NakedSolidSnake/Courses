#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <util/util.h>

#define MAXPENDING  5

static void handleTCPClient(int clntSocket);

int main(int argc, char *argv[])
{
  int servSock;
  int clntSock;

  struct sockaddr_in echoServAddr;
  struct sockaddr_in echoClntAddr;
  unsigned short echoServPort;

  unsigned int clntLen;

  if(argc != 2)
  {
    fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]);
    exit(1);
  }

  echoServPort = atoi(argv[1]);

  if((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    dieWithError("socket() failed");

  memset(&echoServAddr, 0, sizeof(echoServAddr));
  echoServAddr.sin_family = AF_INET;
  echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  echoServAddr.sin_port = htons(echoServPort);

  if(bind(servSock, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) < 0)
    dieWithError("bind() failed");

  if(listen(servSock, MAXPENDING) < 0)
    dieWithError("listen() failed");

  for(;;)
  {
    clntLen = sizeof(echoClntAddr);

    if((clntSock = accept(servSock, (struct sockaddr *) &echoClntAddr, &clntLen)) < 0)
      dieWithError("accept() failed");

    printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));

    handleTCPClient(clntSock);
  }
  

  return EXIT_SUCCESS;
}

#define RCVBUFSIZE 32


static void handleTCPClient(int clntSocket)
{
  char echoBuffer[RCVBUFSIZE];
  int recvMsgSize;

  if((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
    dieWithError("recv() failed");

  while(recvMsgSize > 0)
  {
    if(send(clntSocket, echoBuffer, recvMsgSize, 0) != recvMsgSize)
      dieWithError("send() failed");

    if((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
      dieWithError("recv() failed");
  }

  close(clntSocket);
}
