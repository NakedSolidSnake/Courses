#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <servertcp/servertcp.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <util/util.h>

#define MAXPENDING 5
#define RCVBUFSIZE 32

void handleTCPClient(int clntSocket)
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

int createTCPServerSocket(unsigned short port)
{
  int sock;
  struct sockaddr_in echoServAddr;

  if((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    dieWithError("socket() failed");

  echoServAddr.sin_family = AF_INET;
  echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  echoServAddr.sin_port = htons(port);

  if(bind(sock, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) < 0)
    dieWithError("bind() failed");

  if(listen(sock, MAXPENDING) < 0)
    dieWithError("listen() failed");

  return sock;
}

int acceptTCPConnection(int servSock)
{
  int clntSock;
  struct sockaddr_in echoClntAddr;
  unsigned int clntLen;

  clntLen = sizeof(echoClntAddr);

  if((clntSock = accept(servSock, (struct sockaddr *)&echoClntAddr, &clntLen)) < 0)
    dieWithError("accept() failed");

  printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));

  return clntSock;
}
